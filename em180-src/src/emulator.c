/* emulator.c

   Main program and Command-line interpreter functions to run the
   emulator. This is an interface between the grammar contained
   in emucmd.y and the functions actually implementing the emulator.
   The functionality placed here greatly reduces the complexity of emucmd.y.

   The emulator functions report any errors to stdout.

   modified on Sun Feb  3 18:56:17 GMT 2002 by jdw
   modified on Wed May 14 11:38:53 BST 1997 by don
   modified on Wed May  7 15:03:50 BST 1997 by don
   Created 1.0 on Fri Apr 18 11:51:33 BST 1997 by don
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <Z80.h>
#include "terminal.h"
#include "cmdtypes.h"
#include "store.h"
#include "download.h"
#include "registers.h"
#include "help.h"
#include "z80state.h"
#include "watch.h"
#include "emulator.h"

#define TRUE (1==1)
#define FALSE (!TRUE)

#define LINES 10	/* Default lines of output for a command */
#define WBPOINTS 10	/* Maximum number of watch/breakpoints allowed */
#define DEFAULT_RUNLIMIT 10000 /* Max instructions to run for without a break */
char *banner =  "64180 Emulator v1.3(alpha).\n\n"
			"This software is provided WITHOUT ANY WARRANTY. This software\n"
			"is NOT endorsed by the Department, and if it produces incorrect\n"
			"results, NONE of the authors will be held responsible.\n" ;
char *prompt = ":";


/*******************************************************************/
/* Main program */
int main (int argc, char *argv[]) {
  printf("\n\n%s\n\n",banner);
  printf("%s ", prompt); fflush(stdout);
  if (!init_emulator()) {
    printf("Cannot start Z80 emulator. Aborting\n"); 
    exit(-1);
  }
  yyparse();	/* Calls Emulator functions (below) */
  stop_emulator();
  printf("\n\nEmulator finished. Bye!\n\n");
  return 0 ;
}
/*******************************************************************/


/*******************************************************************/
/* Emulator globals */
Z80 *cpu;
int current_address;
int watch_alarm;
int watch_number;
int watch_address;
int break_alarm;
int break_number;
int ins_alarm , halt_alarm ;
int ins_count;
int intrupt;
int lastPC;
int runlimit = DEFAULT_RUNLIMIT ;
/* SBC emulation */
int sbc_emu_mode , sbc_icr ;
int sbc_asci0_controla , sbc_asci1_controla ;
int sbc_asci0_controlb , sbc_asci1_controlb ;
int sbc_asci0_stat , sbc_asci1_stat ;
int sbc_asci0_last_transmitted , sbc_asci1_last_transmitted ;

struct watchrange {
  int Addr1;
  int Addr2;
}watchp[WBPOINTS];

int breakp[WBPOINTS];

/*******************************************************************/

/*******************************************************************/
/* Emulator Initialisation and shutdown functions */

int init_emulator() {
  int i;

  current_address = 0;
  cpu = (Z80 *)malloc(sizeof(Z80));
  if (cpu == NULL) return 0;
  ResetZ80(cpu);
  buildMem();  /* Initialises store.o data structures. */
  current_address = -1; 
  watch_alarm = FALSE;
  watch_number = 0;
  watch_address = 0x0000;
  break_alarm = FALSE;
  break_number = 0;
  ins_alarm=0;
  halt_alarm=0;
  ins_count=0;

  /* jdw: SBC emulation */
  sbc_emu_mode = 0 ;
  sbc_icr = 0 ;
  sbc_asci0_controla = 0x10 ;	/* RTS bit is set on reset */
  sbc_asci1_controla = 0x00 ;
  sbc_asci0_controlb = sbc_asci1_controlb = 0 ;
  sbc_asci0_stat = sbc_asci1_stat = 0 ;
  sbc_asci0_last_transmitted = sbc_asci1_last_transmitted = 0 ;

  intrupt=-1;
  lastPC=(int)cpu->PC.W;
  for(i=0;i<WBPOINTS;i++) {
    watchp[i].Addr1 = -1; watchp[i].Addr2 = -1;
    breakp[i] = -1;
  }
  return 1;
}

int stop_emulator() {
  if (cpu != NULL) free(cpu);
  releaseMem();
  return 1;
}

/*******************************************************************/
/* The following functions are all called from yyparse (emucmd.y) */
int reset() {
  printf("Resetting CPU\n");
  ResetZ80(cpu);
}

int help(int cmd) {
  int i=0;
  while(helptab[i].cmd != -1) {		/* -1 is end-of-table marker */
    if (helptab[i].cmd == cmd) {
      printf("%s\n", helptab[i].text);
      break;
    }
    i++;
  }
  if (helptab[i].cmd == -1) 
    printf("Sorry!: No Help available for command\n\n");
}

int display() {
  char buffer[TERMSIZE];
  printf("%s\n",z80state(cpu, buffer));
}

int call_exit() {  /* Returns 1 to shut down system */
/* jdw: do not ask the user any more. */
	return 1 ;
	/*
  int c;
  printf("\nExit from emulator: Are you sure(y/n)? "); fflush(stdout);
  do {
    c = tolower(getchar()); 
  } while (!((c=='y')||(c=='n')));
  if (c=='y')
    return 1;
  printf("\n");
  getchar();	* get the trailing '\n' *
  return 0; */
}

int build_mem(int type, Number addr1, Number addr2) {
  if((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  switch(type) {
    case RAMM:
      printf("Building RAM from %04Xh to %04Xh\n",addr1.val,addr2.val);
      setMem(addr1.val, addr2.val, type);
      break;
    case ROMM:
      printf("Building ROM from %04Xh to %04Xh\n",addr1.val,addr2.val);
      setMem(addr1.val, addr2.val, type);
      break;
    default:
      printf("UNKNOWN MEMORY TYPE\n");
      return 0;
  }
  return 1; 
}

int set_mem(Number addr1, Number addr2, Number value) {
/* Uses little-endian byte order. */
  int i, b, bytes, val, usingPtr;

  if (value.bits == 0) { /* Setting value of 'current_address' */
    if (addr1.bits != 16) {
      printf("Write pointer must be 16 bits!\n");
      return 0;
    }
    current_address = addr1.val;
    return 1;
  }
 
  if (addr1.bits == 0) { /* Using 'current_address' */
    if (current_address == -1) {
      printf("Write pointer unset (use 'set addr')\n");
      return 0;
    }
    addr1.val = current_address; addr1.bits = 16;
    addr2.val = current_address; addr2.bits = 16;
    usingPtr = TRUE;
  } else {
    usingPtr = FALSE;
  }

  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }

  bytes = (value.bits/8)+((value.bits%8 == 0)?0:1);
  if (bytes == 0) {
    printf("This should never happen at %d (%s)\n", __LINE__, __FILE__);
    return 0;
  }
  printf("Writing %0Xh (%d bytes) ", value.val, bytes);
  if (addr1.val == addr2.val)
    printf("at %04Xh\n", addr1.val);
  else
    printf("across %04Xh-%04Xh\n",addr1.val,addr2.val);
  for(i=addr1.val; i<=addr2.val; i += bytes) {
    val = value.val;
    for (b=0; b<bytes; b++) {
      burn(i+b, (val >> (b*8))&0xFF);  /* Can write to ROM also */
    }
  }
  if (usingPtr) current_address += bytes;
  return 1;
}
 
int set_register(Register reg, Number value) {
  if (value.bits > reg.bits) {
    printf("Value (%d bits) is longer than register! (%d bits)\n",
            value.bits, reg.bits);
    return 0;
  }
  if (reg.bits == 8)
    set8(cpu, reg.label, value.val);
  else if (reg.bits == 16)
    set16(cpu, reg.label, value.val);
  else
    return 0;

  return 1;
}

/* jdw: Engage SBC (Single Board Computer) emulation mode.
 * In this mode, the two ASCI serial ports are emulated.
 */
int sbc_emu_mode_on ( void )
{
	printf ( "64180 Single Board Computer emulation is on.\n" ) ;
	sbc_emu_mode = TRUE ;
	return 1;
}

/* jdw: Sets the maximum number of instructions to be run at once.
 */
int set_max ( char * max_instructions_str )
{
	int max_instructions = atoi ( max_instructions_str ) ;

	if ( max_instructions > 0 )
	{
		runlimit = max_instructions ;
		printf ( "No more than %ld instructions will be run at once.\n" , 
					runlimit ) ;
	} else {
		printf ( "Invalid maximum: must be greater than zero.\n" ) ;
	}
	return 1;
}

int display_memory(Number addr1, Number addr2, int size) {
/* Relies on definition of BYTE_SIZE etc... (1,2,4). */
  int wordLength;
  char str[TERMSIZE];

  if (addr1.bits == 0) {	/* Use SP */
    addr1.val = (cpu->SP.W) - 16; addr1.bits = 16;
  }
  if (addr2.bits == 0) {
    addr2.val = addr1.val + 32; addr2.bits = 16;
  }
  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  if (addr1.val > addr2.val) {
    printf("Start address exceeds finish address!\n");
    return 0;
  }
  printf("%s\n",
         monitor(addr1.val, (addr2.val-addr1.val), 2, size, 1, RdZ80, str));
   
  return 1;
}

int disassemble_memory(Number addr1, Number addr2) {
  char str[TERMSIZE];

  if (addr1.bits == 0) {	/* Use PC */
    addr1.val = cpu->PC.W; addr1.bits = 16;
  }
  if (addr2.bits == 0) {
    addr2.val = addr1.val + TERMHEIGHT/2;  /* A very approximate count */
    addr2.bits = 16;
  }
  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Addresses must be 16-bit values\n");
    return 0;
  }
  if (addr1.val > addr2.val) {
    printf("Start address exceeds finish address!\n");
    return 0;
  }
  printf("%s\n", disass(addr1.val, addr2.val, RdZ80, str));
  return 1;
}

int load_object(char *fname, Number addr) {
  int loaded;
  if (addr.bits != 16) {
    printf("Load point start must be 16-bit\n");
    return 0;
  }
  printf("Load object file <%s> at %04Xh\n",fname,addr.val);
  loaded = download(fname, addr.val, 0);
  if (loaded == 0) {
    printf("Error: %s\n", downloadErr);
    return 0;
  } else {
    printf("Loaded %d bytes.\n", loaded);
  }
  return 1;
}

int set_break(Number addr) {
  int i;
  if (addr.bits != 16) {
    printf("Breakpoint address must be 16-bits\n");   
    return 0;
  }
  for(i=0;i<WBPOINTS;i++) {
    if (breakp[i] == -1) {  /* Available... */
      breakp[i] = addr.val;
      printf("Set breakpoint at %04Xh\n", addr.val);
      break;
    }
  }
  if (i<WBPOINTS) {
    return 1;
  } else {
    printf("Too many breakpoints set!\n");
    return 0;
  }
}

int set_watch(Number addr1, Number addr2) {
  int i;
  if (addr2.bits == 0) {
    addr2.val = addr1.val;
    addr2.bits = 16;
  }
  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Watch address range values must be 16-bit!\n");   
    return 0;
  }
  for(i=0;i<WBPOINTS;i++) {
    if (watchp[i].Addr1 == -1) {  /* Available... */
      watchp[i].Addr1 = addr1.val;
      watchp[i].Addr2 = addr2.val;
      printf("Set watch over %04Xh-%04Xh\n", addr1.val, addr2.val);
      break;
    }
  }
  if (i<WBPOINTS) {
    return 1;
  } else {
    printf("Too many watch ranges set!\n");
    return 0;
  }
}

int show_points() {
  int i;
  printf("Breakpoints:\n");
  for(i=0;i<WBPOINTS;i++) {
    if (breakp[i] != -1) {
      printf("\t%d: %04Xh\n",i,breakp[i]);
    } else {
      break;
    }
  }
  printf("Watch ranges:\n");
  for(i=0;i<WBPOINTS;i++) {
    if (watchp[i].Addr1 != -1) {
      printf("\t%d: %04Xh-%04Xh\n",i,watchp[i].Addr1,watchp[i].Addr2);
    } else {
      break;
    }
  }
  printf("\n");
}

int clear_break() {
  int i;
  printf("Clearing all Breakpoints...\n");
  for (i=0; i<WBPOINTS;i++) {
    if (breakp[i] == -1) break;
    printf("\tClearing breakpoint at %04Xh\n",breakp[i]);
    breakp[i] = -1;
  }
  return 1;
}

int clear_watch() {
  int i;
  printf("Clearing all Watchpoints...\n");
  for (i=0; i<WBPOINTS;i++) {
    if (watchp[i].Addr1 == -1) break;
    printf("\tClearing watch on %04Xh-%04Xh\n",watchp[i].Addr1,watchp[i].Addr2);
    watchp[i].Addr1 = -1; watchp[i].Addr2 = -1;
  }
  return 1;
}

/*********************************************************************/
/* Managing CPU execution... */
int step() {
  char str[TERMWIDTH];
  
  lastPC=cpu->PC.W;
  printf("%s", disass(cpu->PC.W,-1,RdZ80,str));
  ExecZ80(cpu);
}

int interrupt(Number vector) {
  if (vector.bits == 0) {
    vector.val = 0x0066;  /* Non-maskable interrupt vector */
    vector.bits = 16;
  }
  if (vector.bits != 16) {
    printf("Interrupt vector must be 16 bits!\n");
    return 0;
  }

  intrupt = vector.val;
  printf("Setting interrupt to vector %04Xh\n", intrupt);
  if ((((cpu->IFF)&0x01) == 0) && (vector.val != 0x0066)) {
    printf("Warning: Maskable interrupt raised and not enabled (IFF = 0)\n");
  }
  return 1;
}

int run(Number entry) {
  char str[TERMWIDTH];
  int stop;

  if (entry.bits == 0) {
    entry.val = cpu->PC.W;
    entry.bits = 16;
  }
  if (entry.bits < 16) {
    printf("Entry point address must be 16 bits!\n");
    return 0;
  }
  printf("Running from %04Xh...\n",entry.val);
  watch_alarm = FALSE;
  break_alarm = FALSE;
  ins_alarm = FALSE;
  halt_alarm = FALSE;
  ins_count = 0;
  cpu->PC.W = entry.val;
  cpu->Trace = (byte)1; /* So debug is called... */
  cpu->IPeriod = (byte)1; /* Interrupt checked every cycle */
  for(;;) {
    stop = RunZ80(cpu);
    printf("...Execution stopped at %04Xh\n",stop);
    if (watch_alarm) {
      printf("Access to %04Xh hit Watch point %d (%04Xh-%04Xh).\n\n",
              watch_address, watch_number,
              watchp[watch_number].Addr1, watchp[watch_number].Addr2);
      break;
    }
    if (break_alarm) {
      printf("Hit breakpoint %d (not executed)\n%s\n", break_number,
             disass(cpu->PC.W,-1,RdZ80,str));
      break;
    }
    ins_count = 0;
    if (ins_alarm) {
      /* int c, cont; */
	  char input [ 5 ] ;
      printf("Executed %d instructions. Continue(y/n)? ", runlimit );
	 /* jdw: I found the original getchar method doesn't work well if 
	  * the input is coming from a pipe. Use fgets instead. */

     /*  cont = (getchar() == 'y'); getchar(); * get cr also *
      if (!cont) break; */

	  fgets ( input , 4 , stdin ) ;
	  if ( toupper ( input [ 0 ] ) != 'Y' )
	  {
		  break ;
	  }
    }
    if (halt_alarm) {
      int c, cont;
      printf("HALT instruction reached.\n" ) ;
      break;
    }
    if (cpu->TrapBadOps == (byte)1) { /* Is reported by z80emu/Z80.c code */
      cpu->TrapBadOps = 0;
      printf("Bad Opcode. Terminating run.\n");
      break;
    }
  }
  return 1;
}

/***************************************************************/
/* Functions required by Z80.o (see Z80.h for details) */
void PatchZ80(register Z80 *R) { /* No patching. */
}

/* No emulation of IO ports, except in SBC (single board computer) 
 * emulation mode, in which some 64180 features are emulated.. */
byte InZ80(register word Port) 
{ 
  int invalid;

	if ( sbc_emu_mode )		/* jdw */
	{
		/* Is the instruction attempting to access any of the internal
		 * 64180 devices? Check the I/O Control Register (ICR).
		 * IOSTOP bit (0x20) must be clear, and the top two bits must
		 * match the Port. */
		if (( ! ( sbc_icr & 0x20 ))
		&& (( Port & 0xc0 ) == ( sbc_icr & 0xc0 )))
		{
			/* The ICR and ITC registers are emulated along with
			 * all of the ASCI registers. The timer, free running counter,
			 * CSIO, timer, and DMA registers are not emulated. */
			switch ( Port & 0x3f )
			{
				case 0x00 :		/* ASCI Control A 0 */
								return sbc_asci0_controla ;
				case 0x01 :		/* ASCI Control A 1 */
								return sbc_asci1_controla ;
				case 0x02 :		/* ASCI Control A 0 */
								return sbc_asci0_controlb ;
				case 0x03 :		/* ASCI Control A 1 */
								return sbc_asci1_controlb ;
				case 0x04 :		/* ASCI STAT0 */
								/* No errors, no data received,
								 * and all transmitted data has been sent */
								return ( sbc_asci0_stat & 0x09 ) | 0x02 ;
				case 0x05 :		/* ASCI STAT1 */
								/* No errors, no data received,
								 * and all transmitted data has been sent */
								return ( sbc_asci1_stat & 0x0d ) | 0x02 ;
				case 0x06 :		/* ASCI 0 TDR */
								return sbc_asci0_last_transmitted ;
				case 0x07 :		/* ASCI 1 TDR */
								return sbc_asci1_last_transmitted ;
				case 0x08 :		/* ASCI 0 RDR */
								return 0 ;
				case 0x09 :		/* ASCI 1 RDR */
								return 0 ;
				case 0x34 :		/* Interrupt Trap Control register. */
								return 0 ;	/* zero: no traps occurred */
				case 0x3f :		/* I/O Control Register */
								return sbc_icr ;
			}
		}
	}

  printf("Reading from I/O port %04Xh (PC=%04Xh) ", Port, lastPC);

  invalid = TRUE;
  /* yylex(); Get cr */
  while (invalid) {
    printf("value[00h]?: ");
    fflush(stdout);
    invalid = (yylex() != VALUE);
    if (!invalid)
      invalid = (yylval.val.bits != 8);

	/* jdw: detect end of a script piped into the emulator */
	if ( feof ( stdin ) )
	{
		printf ( "\n\nEnd of file on the input. Goodbye!\n" ) ;
		exit ( 1 ) ;
	}
  }
  printf("Instruction reads %02Xh\n", yylval.val.val);
  return (byte)(yylval.val.val);
}

void OutZ80(register word Port, register byte Value) {

	if ( sbc_emu_mode )		/* jdw */
	{
		/* Is the instruction attempting to access any of the internal
		 * 64180 devices? Check the I/O Control Register (ICR). */
		if (( ! ( sbc_icr & 0x20 ))
		&& (( Port & 0xc0 ) == ( sbc_icr & 0xc0 )))
		{
			/* The ICR and ITC registers are emulated along with
			 * all of the ASCI registers. The timer, free running counter,
			 * CSIO, timer, and DMA registers are not emulated. */
			switch ( Port & 0x3f )
			{
				case 0x00 :		/* ASCI Control A 0 */
								sbc_asci0_controla = Value ;
								return ;
				case 0x01 :		/* ASCI Control A 1 */
								sbc_asci1_controla = Value ;
								return ;
				case 0x02 :		/* ASCI Control A 0 */
								sbc_asci0_controlb = Value ;
								return ;
				case 0x03 :		/* ASCI Control A 1 */
								sbc_asci1_controlb = Value ;
								return ;
				case 0x04 :		/* ASCI STAT0 */
								sbc_asci0_stat = Value ;
								return ;
				case 0x05 :		/* ASCI STAT1 */
								sbc_asci1_stat = Value ;
								return ;
				case 0x06 :		/* ASCI 0 TDR */
								sbc_asci0_last_transmitted = Value ;
								fputc ( Value , stdout ) ;
								fflush ( stdout ) ;
								return ;
				case 0x07 :		/* ASCI 1 TDR */
								sbc_asci1_last_transmitted = Value ;
								fputc ( Value , stdout ) ;
								fflush ( stdout ) ;
								return ;
				case 0x08 :		/* ASCI 0 RDR */
								return ;
				case 0x09 :		/* ASCI 1 RDR */
								return ;
				case 0x34 :		/* Interrupt Trap Control register. */
								return ;
				case 0x3f :		/* I/O Control Register */
								sbc_icr = Value ;
								return ;
			}
		}
	}
  printf("Writing %02Xh to I/O port %04Xh (PC=%04Xh)\n",
         Value, Port, lastPC);
}

word LoopZ80(register Z80 *R) { /* Sets interrupts */
  word rtn;
  if (intrupt != -1) {
    rtn = (word)intrupt;
    intrupt = -1;
    return rtn;		
  }
  return INT_NONE;
}

byte DebugZ80(register Z80 *R) { /* Test to see if should stop. */
  int i;			 /* state in watch_alarm, break_alarm. */
  int ops_alarm ;

  /* jdw: Break on HALT */
  halt_alarm = ( RdZ80 ( R -> PC.W ) == 0x76 /* halt opcode */ ) ;

  lastPC = (int)R->PC.W;	 /* available during exe of that instruction. */
  if (watch_alarm) return FALSE;
  for (i=0; i<WBPOINTS; i++) {
    if (breakp[i] == -1)
      break;
    else if (R->PC.W == breakp[i]) {
      break_alarm = TRUE; break_number = i;
      break;
    }
  }
  ins_alarm = (ins_count++ >= runlimit );
  ops_alarm = (R->TrapBadOps == (byte)1);
  return !(break_alarm || watch_alarm || ins_alarm || ops_alarm || halt_alarm);
}

/****************************************************************/
/* Support functions required (watch&breakpointing) */
void check_watch(register word addr) {
  int i; /* Check addr with respect to watchp set. Set 'watch_alarm' */
         /* if hit, otherwise ignore. Called by RdZ80, WrZ80 (in store.c). */

  for(i=0;i<WBPOINTS;i++) {
    if (watchp[i].Addr1 == -1)
      break;
    else if ((addr >= watchp[i].Addr1) && (addr <= watchp[i].Addr2)) {
      watch_alarm = TRUE; watch_number = i; watch_address = addr;
      break;
    }
  }
}
