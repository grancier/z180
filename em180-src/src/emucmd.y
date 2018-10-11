/* emucmd.y

   YACC (BISON) Input file, specifying command line grammar for
   driving the Z80 development system emulator.

   modified Sun Feb  3 19:35:39 GMT 2002 by jdw
   Created 1.0 on Tue Apr 15 09:03:14 BST 1997 by don
*/

/* Any required inclusions/definitions */
%{
#define YYDEBUG 1
#include <stdio.h>
#include "cmdtypes.h"
#include "store.h"
#include "emulator.h"
void yyerror(char *s) {
  printf("Syntax Error. Input Ignored.\n");
}

%}



/* BISON declarations */
%token HELP
%token RESET
%token DISPLAY
%token INTERRUPT
%token LOAD
%token SET
%token RAM
%token ROM
%token STEP
%token RUN
%token BREAK
%token WATCH
%token CLEAR
%token SHOW
%token MEMORY
%token DISASSEMBLE
%token EXIT
%token SIZE_TAG
%token VALUE
%token BAD_VALUE
%token REGISTER
%token BAD_REGISTER
%token STRING
%token SBCMODE
%token MAX

%union {
	Register reg;
	Number	 val;
	char str[255];
	int size;
}

%type <val> VALUE 
%type <str> STRING
%type <reg> REGISTER
%type <size> SIZE_TAG
%type <size> cmd_name

/* Grammar follows... */
%%
input:	/* empty string */
	| input line
;

line:	'\n'		{ printf("%s ", prompt); fflush(stdout); }
	| command '\n'	{ printf("%s ", prompt); fflush(stdout); }
	| error '\n'	{ yyerrok; printf("%s ", prompt); fflush(stdout); }
;


command:	help		{  }
	|	EXIT		{ if (call_exit()) return 1; }
	|	RESET  		{ reset(); }
	|	DISPLAY		{ display(); }
	|	set		{  }
	|	build_mem	{  }
	|	load_obj	{  }
	|	memory		{  }
	|	disassemble	{  }
	|	STEP		{ step(); }
	|	run		{  }
	|	break		{  }
	|	watch		{  }
	|	clear		{  }
	|	SHOW		{ show_points(); }
	|	interrupt	{  }
;

cmd_name:	HELP		{$$ = HELP}
	|	EXIT		{$$ = EXIT}
	|	RESET		{$$ = RESET}
	|	DISPLAY		{$$ = DISPLAY}
	|	SET		{$$ = SET}
	|	RAM		{$$ = RAM}
	|	ROM		{$$ = RAM; /* No duplication! */}
	|	LOAD		{$$ = LOAD}
	|	MEMORY		{$$ = MEMORY}
	|	DISASSEMBLE	{$$ = DISASSEMBLE}
	|	STEP		{$$ = STEP}
	|	RUN		{$$ = RUN}
	|	BREAK		{$$ = BREAK}
	|	WATCH		{$$ = WATCH}
	|	CLEAR		{$$ = CLEAR}
	|	SHOW		{$$ = SHOW}
	|	INTERRUPT	{$$ = INTERRUPT}
;

help:		HELP		{ help(0); }
	|	HELP cmd_name	{ help($<size>2); }

build_mem:	RAM VALUE VALUE {
		  build_mem(RAMM, $<val>2, $<val>3);
		}
	|	ROM VALUE VALUE {
		  build_mem(ROMM, $<val>2, $<val>3);
		}
;

set:		SET VALUE {
		  set_mem($<val>2,NULL_NUMBER,NULL_NUMBER);
		}
	|	VALUE {
		  set_mem(NULL_NUMBER,NULL_NUMBER,$<val>1);
		}
	|	SET VALUE VALUE {
		  set_mem($<val>2,$<val>2,$<val>3);
		}
	|	SET VALUE VALUE VALUE {
		  set_mem($<val>2,$<val>3,$<val>4);
		}
	|	SET REGISTER VALUE {
		  set_register($<reg>2, $<val>3);
		}
    |   SET SBCMODE { sbc_emu_mode_on () ;
		}
    |   SET MAX STRING { set_max ( $<str>3 ) ;
		}
;

interrupt: 	INTERRUPT   {
		  interrupt(NULL_NUMBER);
		}
	|	INTERRUPT VALUE {
		  interrupt($<val>2);
		}
;

memory:		MEMORY {
		  display_memory(NULL_NUMBER,NULL_NUMBER,BYTE_SIZE);
		}
	|	MEMORY VALUE {
		  display_memory($<val>2,NULL_NUMBER,BYTE_SIZE);
		}
	|	MEMORY SIZE_TAG {
		  display_memory(NULL_NUMBER,NULL_NUMBER,$<size>2);
		}
	|	MEMORY VALUE SIZE_TAG {
		  display_memory($<val>2,NULL_NUMBER,$<size>3);
		}
	|	MEMORY VALUE VALUE {
		  display_memory($<val>2,$<val>3,BYTE_SIZE);
		}
	|	MEMORY VALUE VALUE SIZE_TAG {
		  display_memory($<val>2,$<val>3,$<size>4);
		}

disassemble:	DISASSEMBLE VALUE {
		  disassemble_memory($<val>2,NULL_NUMBER);
		}
	|	DISASSEMBLE VALUE VALUE {
		  disassemble_memory($<val>2,$<val>3);
		}

load_obj:	LOAD STRING VALUE {
		  load_object($<str>2, $<val>3);
		}
;
	
run:		RUN {
		  run(NULL_NUMBER);
		}
	|	RUN VALUE {
		  run($<val>2);
		}
;

break:		BREAK VALUE {
		  set_break($<val>2);
		}
;

watch:		WATCH VALUE {
		  set_watch($<val>2,$<val>2);
		}
	|	WATCH VALUE VALUE {
		  set_watch($<val>2,$<val>3);
		}
;

clear:		CLEAR BREAK {
		  clear_break();
		}
	|	CLEAR WATCH {
		  clear_watch();
		}
;
%%




#ifdef TEST
/**********************************************************************/
/* Stand-alone testing */

char *prompt = "<test>:";

main (int argc, char *argv[]) {
  printf("\n\nCalling the parser...\n\n");
  if (argc > 1) yydebug=1; else yydebug=0;
  printf("%s ", prompt); fflush(stdout);
  yyparse();
  printf("\n\nTest finished. Bye!!...\n\n");
}

int reset() {
  printf("Reset Called\n");
}

int help(int cmd) {
  printf("Help Called with token %d\n", cmd);
}

int display() {
  printf("Display Called\n");
}

int step() {
  printf("Step Called\n");
}

int call_exit() {
  printf("Call_Exit Called\n");
  return 0;
}

int interrupt(Number vector) {
  printf("interrupt called\n");
  if (vector.bits == 0)
    printf("No vector specified\n");
  else
    printf("Vector=%02x\n", vector.val);
  return 1;
}

int build_mem(int type, Number addr1, Number addr2) {
  if((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  switch(type) {
    case RAMM:
      printf("Building RAM from %04x to %04x\n",addr1.val,addr2.val);
      break;
    case ROMM:
      printf("Building ROM from %04x to %04x\n",addr1.val,addr2.val);
      break;
    default:
      printf("UNKNOWN MEMORY TYPE\n");
  }
  return 1; 
}

int set_mem(Number addr1, Number addr2, Number value) {
  if (addr1.bits == 0) {	/* Use counter */
    addr1.val = 0x0000; addr1.bits = 16;
    addr2.val = 0xFFFF; addr2.bits = 16;
  } else if((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  if (value.bits <= 8)
    printf("Writing byte %02x across %04x-%04x\n",
           value.val,addr1.val,addr2.val);
  else if (value.bits <= 16)
    printf("Writing short %04x across %04x-%04x\n",
           value.val,addr1.val,addr2.val);
  else if (value.bits <= 32)
    printf("Writing word %08x across %04x-%04x\n",
           value.val,addr1.val,addr2.val);
 
  return 1;
}
 
int set_register(Register reg, Number value) {
  printf("Set register called\n");
  printf("Writing %0x to register %d(%d)\n", value.val, reg.label, reg.bits);
  return 1;
}

int display_memory(Number addr1, Number addr2, int size) {
  printf("Memory called\n");
  if (addr1.bits == 0) {	/* Use counter */
    addr1.val = 0x0000; addr1.bits = 16;
  }
  if (addr2.bits == 0) {
    addr2.val = 0xFFFF; addr2.bits = 16;
  }
  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  if (addr1.val > addr2.val) {
    printf("Start address exceeds finish address!\n");
    return 0;
  }
  switch(size) {
    case BYTE_SIZE:
      printf("Display mem as bytes from %04x to %04x\n", addr1.val, addr2.val);
      break;
    case SHORT_SIZE:
      printf("Display mem as shorts from %04x to %04x\n", addr1.val, addr2.val);
      break;
    case WORD_SIZE:
      printf("Display mem as words from %04x to %04x\n", addr1.val, addr2.val);
      break;
    default:
      printf("What size???\n");
  }
  return 1;
}

int disassemble_memory(Number addr1, Number addr2) {
  printf("Disassemble memory called\n");
  if (addr1.bits == 0) {	/* Use counter */
    addr1.val = 0x0000; addr1.bits = 16;
  }
  if (addr2.bits == 0) {
    addr2.val = 0xFFFF; addr2.bits = 16;
  }
  if ((addr1.bits != 16) || (addr2.bits != 16)) {
    printf("Memory block limits must be 16-bit values\n");
    return 0;
  }
  if (addr1.val > addr2.val) {
    printf("Start address exceeds finish address!\n");
    return 0;
  }
  printf("Disassemble from %04x to %04x\n", addr1.val, addr2.val);

  return 1;
}

int load_object(char *fname, Number addr) {
  printf("Load Object called\n");
  if (addr.bits != 16) {
    printf("Load point start must be 16-bit\n");
    return 0;
  }
  printf("Load object file <%s> at %04x\n",fname,addr.val);
  return 1;
}

int run(Number entry) {
  printf("Run called\n");
  if (entry.bits == 0) {
    entry.bits = 16;
    entry.val = 0x2345;
  }
  printf("Running from entry point %04x\n",entry.val);
  return 1;
}

int set_break(Number addr) {
  printf("Break called\n");
  if (addr.bits != 16) {
    printf("Breakpoint address must be 16-bits\n");   
    return 0;
  }
  printf("Setting breakpoint at %04x\n", addr.val);
  return 1;
}

int clear_break() {
  printf("Clear Break called\n");
  return 1;
}

#endif /* TEST */
