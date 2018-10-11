/*
 *	Example: linking a program generated with the MS Basic Compiler 
 *	and then converted with the rel2z80 tool to run on the ZX Spectrum.
 *	The BASIC program is linked as if it was a library, and this one
 *	provides the necessary entries, main() included.
 *	This is a sort of "Debugging runtime".. written in C !
 *	There is some inline assembly to read/convert parameters.
 *	Not all the functions are implemented, anyway some simple program 
 *	can be linked and 'run' (or 'debugged' !).
 *
 *
 *	Given a REL file generated by the BASIC Compiler in CP/M, first convert it:
 *	> rel2z80 HILO.REL
 *
 *	This will extract a binary object SSMAIN.O
 *	Now link it into a Z80ASM library and copy the lib in your Z88DK tree:
 *
 *	> z80asm -d -ns -nm -xssmain ssmain.o
 *	> copy ssmain.lib "c:\Program Files\z88dk\lib\clibs"
 *
 *	Ok, this program is the new runtime library.  
 *	Compile it referring to SSMAIN as a library to be included:
 *      > zcc +zxansi -lndos -lssmain -lm -lmalloc -create-app -zorg=26000 baslib.c
 *
 *	Now try "a.tap" on your favourite Spectrum emulator !
 *
 *
 *	$Id: baslib.c,v 1.3 2016/09/17 15:07:16 pauloscustodio Exp $
 *
 */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

#include <malloc.h>
#define HPSIZE 2000
HEAPSIZE(HPSIZE)

// Compiled BASIC start address
extern void __LIB__  SSMAIN();

// Begin (initialize runtime env if necessary)
extern void __LIB__  SINI();

// End
extern void __LIB__  SEND();

// Chain - load and run another program.
extern void __LIB__  SCHN();

extern void __LIB__  SRUN();

// Print char
extern void __LIB__  SCHR();

extern void __LIB__  SIN0A();
extern void __LIB__  SIN0B();

extern void __LIB__  SIPUA();
extern void __LIB__  SIPUB();

extern void __LIB__  SLIPA();


extern void __LIB__  SLTMA();
extern void __LIB__  SFMUA();
extern void __LIB__  SFADC();
extern void __LIB__  SGTCC();
extern void __LIB__  SNECE();
extern void __LIB__  SEQCG();
extern void __LIB__  SGTCG();
extern void __LIB__  SEQJG();

// ON GOTO
extern void __LIB__  SOGTA();

// ON GOSUB
//extern void __LIB__  SOGSA();

extern void __LIB__  SCINA();
extern void __LIB__  SCINC();

extern void __LIB__  S530();

// Compare string
extern void __LIB__  SEQTA();

extern void __LIB__  SMID();
extern void __LIB__  SREAA();
extern void __LIB__  SDVDA();
extern void __LIB__  SBSUA();
extern void __LIB__  SSASB();

// LEN string
extern void __LIB__  SLENA();

// Set text width
extern void __LIB__  SWID();

extern void __LIB__  SLFMA();
extern void __LIB__  SFADA();

// float save, put accumulator into specified location
extern void __LIB__  SFASO();
extern void __LIB__  SFASA();

extern void __LIB__  STABA();

extern void __LIB__  SLEF();
extern void __LIB__  SINT();

// RANDOMIZE
extern void __LIB__  SRZ0();
// RND
extern void __LIB__  SRAN();

// Float compare and conditional jump
extern void __LIB__  SLTJA();
extern void __LIB__  SGTJA();
extern void __LIB__  SEQJA();
extern void __LIB__  SNEJA();
extern void __LIB__  SGEJA();
extern void __LIB__  SLEJA();

// Float accumulator compare and conditional jump
extern void __LIB__  SLTJC();
extern void __LIB__  SGTJC();
extern void __LIB__  SEQJC();
extern void __LIB__  SNEJC();
extern void __LIB__  SGEJC();
extern void __LIB__  SLEJC();

extern void __LIB__  SRPT();
extern void __LIB__  SRGT();

extern void __LIB__  SDKN();
extern void __LIB__  SDKM();
extern void __LIB__  SDKC();

extern void __LIB__  SSTMA();

extern void __LIB__  SPV0C();

// Print (no newline)
extern void __LIB__  SPV1A();	// float
extern void __LIB__  SPV1B();	// double precision
extern void __LIB__  SPV1C();	// integer
extern void __LIB__  SPV1D();	// string
// Print (newline)
extern void __LIB__  SPV2A();	// float
extern void __LIB__  SPV2B();	// double precision
extern void __LIB__  SPV2C();	// integer
extern void __LIB__  SPV2D();	// string

extern void __LIB__  SCISA();
extern void __LIB__  SIMUG();
extern void __LIB__  SFMUC();
extern void __LIB__  SFMUE();
extern void __LIB__  SPR0A();
extern void __LIB__  SPR0D();

extern void DOJUMP();

void	*tmem;

#asm
; MS BASIC FP accumulator

	PUBLIC	SAC
.SAC
	defb	0,0,0,0
#endasm


int	B_CHAN = 0;
char	B_FLAGS = ' ';
int	B_RECSIZ = 0;
int	B_TMPINT = 0;
int	B_TMPINT2 = 0;
int	B_TMPINT3 = 0;
float	B_TMPFLOAT;
float	B_TMPFLOAT2;
char	B_TMPSTR [255];
char	B_TMPSTR2 [255];


#ifdef DEBUG
void pause()
{
	int i;
	for (i=0; i<2000; i++)
	  printf("");
}
#endif


void SINI()
{
	#asm
	push	hl
	#endasm

#ifdef DEBUG
	printf("Initializing...\n");
	pause ();
#endif

	heapinit(HPSIZE);
	}


// Chain
void SCHN()
{
	#asm
	call	readstr
	#endasm
#ifdef DEBUG
	printf("SCHN.- LOAD AND RUN ANOTHER PROGRAM: '%s'\n", B_TMPSTR);
	pause ();
#endif
	exit(0);
	}


void SEND()
{
#ifdef DEBUG
	printf("Exiting...\n");
	pause ();
#endif
	exit(0);
	}


void SRUN()
{
#ifdef DEBUG
	printf("SRUN\n");
	pause ();
#endif
	}


void SCHR()
{
	#asm
	ld	(_B_TMPINT),hl
	jr nocls
	ld	a,26
	cp	l
	jr	nz,nocls
	ld	l,12
nocls:
	ld	(mychr),hl
	#endasm

#ifdef DEBUG
	printf("SCHR - print char %u\n",B_TMPINT);
	pause ();
#endif

	#asm
	ld	hl,chrstr
	ret

chrstr:
	defb	1
	defw	mychr
mychr:
	defb	65 
	#endasm

	}


void SLTMA()
{
#ifdef DEBUG
	printf("SLTMA\n");
	pause ();
#endif
	}


void SFMUA()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SFMUA - variable (%u){%f} and (%u){%f} \n", B_TMPINT, B_TMPFLOAT, B_TMPINT2, B_TMPFLOAT2);
	pause ();
#endif
	}


void SFADC()
{
	#asm
	call	read1parm
	ld	hl,_B_TMPFLOAT
	call	store_float
	
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SFADC - variable (%u){%f}\n", B_TMPINT, B_TMPFLOAT);
	pause ();
#endif
	}


// ???
void SGTCC()
{
	#asm
	call	read1parm
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SGTCC - expr (SAC > (%u){%f})\n", B_TMPINT, B_TMPFLOAT);
	pause ();
#endif
	}

void SNECE()
{
#ifdef DEBUG
	printf("SNECE\n");
	pause ();
#endif
	}


void SEQCG()
{
	#asm
	call	read1parm
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SEQCG - (%u)%f \n", B_TMPINT, B_TMPFLOAT);
	pause ();
#endif
	}


// ???
void SGTCG()
{
	#asm
	call	read1parm
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SGTCG - expr (SAC > (%u){%f})\n", B_TMPINT, B_TMPFLOAT);
	pause ();
#endif
	}


void SEQJG()
{
#ifdef DEBUG
	printf("SEQJG\n");
	pause ();
#endif
	}


// ON GOTO
void SOGTA()
{
#asm
	ld	(_B_TMPINT),hl
	
	ld	a,l
	pop	hl
	ld	b,(hl)
	inc	hl
	push	hl
	and	a
	jr	z,zogt

	;cp	1	; default ??
	;jr	z,zogt
	
	inc	b
	cp	b
	jr	nc,zogt

	push	af
	push	bc
;#endasm
;	
;#ifdef DEBUG
;	printf("SOGTA - ON %u GOTO\n", B_TMPINT);
;	pause ();
;#endif
;
;#asm
;	pop	af
;	pop	bc
	
	pop	hl
sogt:
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	dec	a
	jr	nz,sogt
	push	de
	ret
	
zogt:
	pop	hl
	dec	b
noogt:
	inc	hl
	inc	hl
	djnz	noogt
	push	hl

#endasm

#ifdef DEBUG
	printf("SOGTA - ON GOTO, value %u doesn't match\n", B_TMPINT);
	pause ();
#endif
	}


void SCINA()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SCINA - pick %f (%u) and keep its int {%u}\n", B_TMPFLOAT, B_TMPINT, (int)B_TMPFLOAT);
	pause ();
#endif
	B_TMPINT=(int)B_TMPFLOAT;
	
	#asm
	ld	hl,(_B_TMPINT)
	#endasm
	
	}


void SCINC()
{
	printf("SCINC\n");
}


void S530()
{
#ifdef DEBUG
	printf("S530\n");
	pause ();
#endif
	}


void SMID()
{
	#asm
	call	readstr
	#endasm

	printf("SMID - '%s'\n", B_TMPSTR);
}


void SLENA()
{
	#asm
	call	readstr
	#endasm

#ifdef DEBUG
	printf("SLENA - LEN('%s')=%u\n", B_TMPSTR, strlen(B_TMPSTR));
#endif

	B_TMPINT=strlen(B_TMPSTR);
	
}


void SREAA()
{
	printf("SREAA\n");
}


void SDVDA()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SDVDA - %f(%u) / %f(%u)\n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2);
#endif
	
	B_TMPFLOAT=B_TMPFLOAT/B_TMPFLOAT2;
	
	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm
}


void SBSUA()
{
	printf("SBSUA\n");
}



void SSASB()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm
	
	printf("SSASB - $u\n", B_TMPINT);
}


void SEQTA()
{
	
	#asm
	call	read2str
	call	readjpparm
	#endasm

#ifdef DEBUG
	printf("SEQTA - Compare string '%s' with '%s'(%u), if eq jp to %u\n", B_TMPSTR, B_TMPSTR2, B_TMPINT2, B_TMPINT);
	//printf("Result: %s\n",(strcmp ((char *)B_TMPSTR, (char *)B_TMPSTR2) == 0));
	pause ();
#endif

#asm
	ld	hl,_B_TMPSTR
	ld	de,_B_TMPSTR2
.strcmp1
        ld      a,(de)	; Next char from s2
        inc	de	; Ready for next char
        cpi     	; Compare with s1 (and inc hl) -- does not set C flag
        ret	nz	; Different!
        and     a	; Check for end of strings
        jr      nz,strcmp1 ; Round again
; Both strings ended simultaneously 
; now we know *s1=*s2=0, return hl=0
	call	_DOJUMP
#endasm

	}


void SWID()
{
#ifdef DEBUG
	#asm
	ld	(_B_TMPINT),hl
	#endasm
	
	printf("SWID - Set screen text width to %u\n", B_TMPINT);
	pause ();
#endif
	}


void SLFMA()
{
	#asm
	call	read1parm
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm
	
#ifdef DEBUG
	printf("SLFMA - load float constant %f\n", B_TMPFLOAT);
#endif
	
	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm

#ifdef DEBUG
	pause ();
#endif
	}


void SFADA()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm
	
#ifdef DEBUG
	printf("SFADA - %f (%u) + %f (%u) = %f\n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPFLOAT+B_TMPFLOAT2);
#endif
	
	B_TMPFLOAT = B_TMPFLOAT+B_TMPFLOAT2;
	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm

#ifdef DEBUG
	pause ();
#endif
	}


void SFASO()
{
	#asm
	call	read1parm
	ld	hl,SAC
	ld	bc,4
	ldir
	#endasm
	
#ifdef DEBUG
	#asm
	ld	hl,(_B_TMPINT)
	ld	de,(_B_TMPFLOAT)
	call	load_float
	#endasm
	
	printf("SFASO - put result {%f} in (%u)\n", B_TMPFLOAT, B_TMPINT);
	pause ();
#endif

	}


void SFASA()
{
	// I'm unsure.. perhaps I should malloc 4 bytes and update value as a ptr to it ?
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT2)
	ld	de,(_B_TMPINT)
	ld	bc,4
	ldir
	#endasm
	
#ifdef DEBUG
	#asm
	ld	hl,(_B_TMPINT2)
	ld	de,(_B_TMPFLOAT2)
	call	load_float
	#endasm

	printf("SFASA - (%u) = %f\n", B_TMPINT, B_TMPFLOAT2);
	pause ();
#endif
	}


void STABA()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("STABA - Print TAB %u \n", B_TMPINT);
	pause ();
#else
	for ( B_TMPINT2=0; B_TMPINT2<B_TMPINT; B_TMPINT2++)
	    printf(" ");
#endif
	}


void SLEF()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	(_B_TMPINT2),de
	;;ld	a,l
	;;ld	(de),a
	#endasm

#ifdef DEBUG
	printf("SLEF - Left (string in %u),%u\n", B_TMPINT2, B_TMPINT);
	pause ();
#endif
	}


void SINT()
{
	#asm
	ld	hl,SAC
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm

	B_TMPINT = (int) B_TMPFLOAT;

#ifdef DEBUG
	printf("SINT - %f; result: %u\n", B_TMPFLOAT, B_TMPINT);
#endif

	B_TMPFLOAT = (float) B_TMPINT;
	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm
	
#ifdef DEBUG
	pause ();
#endif
	}


void SRZ0()
{
#ifdef DEBUG
	printf("SRZ0 - RANDOMIZE\n");
	pause ();
#endif
	//srand(0);
	}


void SRAN()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm

	B_TMPFLOAT = (rand() / RAND_MAX.0) * (float) B_TMPINT;

#ifdef DEBUG
	printf("SRAN - RND(%u); got: %f\n", B_TMPINT, B_TMPFLOAT);
#endif

	//B_TMPFLOAT = -259.5;

	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm
	
	
	#asm
	ld	hl,SAC
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm
	
#ifdef DEBUG
	printf ("Float stored: %f\n", B_TMPFLOAT);
	pause ();
#endif
	}


void SLTJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SLTJA - if %f (%u) < %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (B_TMPFLOAT < B_TMPFLOAT2)
	  DOJUMP();
	}


void SGTJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SGTJA - if %f (%u) > %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (B_TMPFLOAT > B_TMPFLOAT2)
	  DOJUMP();
	}


void SEQJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SEQJA - if %f (%u) = %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (B_TMPFLOAT == B_TMPFLOAT2)
	  DOJUMP();
	}


void SNEJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SEQJA - if %f (%u) <> %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (B_TMPFLOAT != B_TMPFLOAT2)
	  DOJUMP();
	}


void SGEJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SLEJA - if %f (%u) >= %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (!(B_TMPFLOAT < B_TMPFLOAT2))
	  DOJUMP();
	}


void SLEJA()
{
	#asm
	call	read3jpparms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SLEJA - if %f (%u) <= %f (%u) jump to %u \n", B_TMPFLOAT, B_TMPINT, B_TMPFLOAT2, B_TMPINT2, B_TMPINT3);
	pause ();
#endif
	if (!(B_TMPFLOAT > B_TMPFLOAT2))
	  DOJUMP();
	}


void SLTJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SLTJC - if SAC < (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (B_TMPFLOAT < B_TMPFLOAT2)
	  DOJUMP();
	}


void SGTJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SGTJC - if SAC > (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (B_TMPFLOAT > B_TMPFLOAT2)
	  DOJUMP();
	}


void SEQJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SEQJC - if SAC = (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (B_TMPFLOAT == B_TMPFLOAT2)
	  DOJUMP();
	}


void SNEJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SNEJC - if SAC <> (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (B_TMPFLOAT != B_TMPFLOAT2)
	  DOJUMP();
	}


void SGEJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SGEJC - if SAC >= (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (!(B_TMPFLOAT < B_TMPFLOAT2))
	  DOJUMP();
	}


void SLEJC()
{
	#asm
	call	read2parms
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float
	ld	hl,(_B_TMPINT2)
	ld	(jploc +1 ),hl
	#endasm

#ifdef DEBUG
	printf("SLEJC - if SAC <= (%u) {%f} jp %u\n", B_TMPINT, B_TMPFLOAT, B_TMPINT2);
	pause ();
#endif
	if (!(B_TMPFLOAT > B_TMPFLOAT2))
	  DOJUMP();
	}


void SRPT()
{
	#asm
	ld	(_B_CHAN),de
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("SRPT - put to stream #%u value.. %u \n", B_CHAN, B_TMPINT);
	pause ();
#endif
	}

void SRGT()
{
	#asm
	ld	(_B_CHAN),de
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("SRGT - get from stream #%u value.. %u \n", B_CHAN, B_TMPINT);
	pause ();
#endif
	}


void SDKN()
{
	#asm
	call	readstr
	#endasm
	
	B_FLAGS = B_TMPSTR[0];

#ifdef DEBUG
	printf("SDKN - Init OPEN with flags: '%s'\n", B_TMPSTR);
	pause ();
#endif
	}


void SDKM()
{
	#asm
	ld	(_B_CHAN),bc
	ld	(_B_RECSIZ),hl
	ld	h,d
	ld	l,e
	call	readstr
	#endasm

#ifdef DEBUG
	printf("SDKM - open '%c', %u, '%s', recsize %u \n", B_FLAGS, B_CHAN, B_TMPSTR, B_RECSIZ);
	pause ();
#endif
	}


void SDKC()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("SDKC - close #%u\n", B_TMPINT);
	pause ();
#endif
	}


void SSTMA()
{
#ifdef DEBUG
	printf("SSTMA\n");
	pause ();
#endif
	}


void SIN0A()
{
	#asm
	call	readstr
	pop	hl
	ld	e,(hl)
	inc	hl
	ld	d,0
	ld	(_B_TMPINT),de
	push	hl
	#endasm

#ifdef DEBUG
	printf("SIN0A - Print msg for input: '%s' - flag %u\n", B_TMPSTR, B_TMPINT);
	pause ();
#else
	printf("%s ?  ", B_TMPSTR);
#endif
	}


void SIN0B()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("SIN0B - set up input from #%u\n", B_TMPINT);
	pause ();
#endif
	}


void SLIPA()
{
	#asm
	ld	(_B_TMPINT),hl
	push	hl
	#endasm

#ifdef DEBUG
	printf("SLIPA - line input: put string in location %u\n", B_TMPSTR);
	pause ();
#endif	
	gets (B_TMPSTR);

	#asm
	pop	hl
	#endasm
	}


void SIPUA()
{
	#asm
	call	read1parm
	#endasm
	
	// 10100000001 -- 1281 -- Number   ( byte sequence: 01 07 )
	// 11100000001 -- 1793 -- string   ( byte sequence: 01 05 )

	gets (B_TMPSTR);
	if (!(B_TMPINT & 512))
	{
		B_TMPFLOAT = atof(B_TMPSTR);
#ifdef DEBUG
		printf ("  SIPUA - %f",B_TMPFLOAT);
#endif
	}
	printf ("\n");

#ifdef DEBUG
	pause ();
#endif
	}


void SIPUB()
{
	#asm
	ld	(_B_TMPINT2),hl
	ld	d,h
	ld	e,l
	ld	a,(_B_TMPINT+1)
	and	2
	jr	nz,is_string
	ld	hl,_B_TMPFLOAT
	call	store_float
	;jr	is_num
.is_string
	;ld	hl,_B_TMPSTR
	;call	store_string
	;.is_num
	#endasm

	if (B_TMPINT & 512)
	{
		tmem=malloc(strlen(B_TMPSTR)+3);
		
#ifdef DEBUG
		printf ("\n Malloc of %u bytes; location %u\n", strlen(B_TMPSTR)+3, tmem);
#endif
		
		#asm
		ld	hl,_B_TMPSTR
		ld	de,(_tmem)
		call	store_string
		
		; copy the string ptr onto the variable position
		ld	hl,(_tmem)
		ld	de,(_B_TMPINT2)
		ld	bc,3
		ldir
		#endasm

#ifdef DEBUG
		printf ("\n .entered string %s\n", B_TMPSTR);
#endif
	}
	else
	{
		#asm
		;ld	de,(_B_TMPINT2)
		;call	store_float
		ld	hl,(_B_TMPINT2)
		ld	de,_B_TMPFLOAT
		call	load_float
		#endasm
#ifdef DEBUG
		printf ("\n...entered number %f\n", B_TMPFLOAT);
#endif
	}

#ifdef DEBUG
	printf("SIPUB - string ptr now points to %u\n", B_TMPINT2);
	pause ();
#endif
	}


void SPV0C()
{
#ifdef DEBUG
	printf("SPV0C\n");
	pause ();
#endif
	}


void SPV1A()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm
	
#ifdef DEBUG
	printf("SPV1A - (%u) ", B_TMPINT);
#endif
	printf(" %f ", B_TMPFLOAT);

#ifdef DEBUG
	printf("\n");
	pause ();
#endif
	}


void SPV1B()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_double
	#endasm
	
#ifdef DEBUG
	printf("SPV1B - (%u) ", B_TMPINT);
#endif
	printf(" %f ", B_TMPFLOAT);

#ifdef DEBUG
	printf("\n");
	pause ();
#endif
	}


void SPV1C()
{
	#asm
	ld	h,d
	ld	l,e
	ld	(_B_TMPINT),hl
	#endasm
	
#ifdef DEBUG
	printf("SPV1C - ");
#endif

	printf(" %u ", B_TMPINT);

#ifdef DEBUG
	printf("\n");
	pause ();
#endif
	}


void SPV1D()
{
	#asm
	call	readstr
	#endasm

#ifdef DEBUG
	printf("SPV1D - ");
#endif

	printf("%s", B_TMPSTR);

#ifdef DEBUG
	printf("\n");
	pause ();
#endif
	}


void SPV2A()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_float
	#endasm
	
#ifdef DEBUG
	printf("SPV2A - (%u) ", B_TMPINT);
#endif
	printf(" %f\n", B_TMPFLOAT);

#ifdef DEBUG
	pause ();
#endif
	}


void SPV2B()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	de,_B_TMPFLOAT
	call	load_double
	#endasm
	
#ifdef DEBUG
	printf("SPV2B - (%u) ", B_TMPINT);
#endif
	printf(" %f\n", B_TMPFLOAT);

#ifdef DEBUG
	pause ();
#endif
	}


void SPV2C()
{
	#asm
	ld	h,d
	ld	l,e
	ld	(_B_TMPINT),hl
	#endasm
	
#ifdef DEBUG
	printf("SPV2C - ");
#endif

	printf(" %u\n", B_TMPINT);

#ifdef DEBUG
	pause ();
#endif
	}


void SPV2D()
{
	#asm
	call	readstr
	#endasm

#ifdef DEBUG
	printf("SPV2D - ");
#endif

	printf("%s\n", B_TMPSTR);

#ifdef DEBUG
	pause ();
#endif
	}


void SCISA()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm

#ifdef DEBUG
	printf("SCISA - put int {%u} into float SAC\n", B_TMPINT);
	pause ();
#endif
	B_TMPFLOAT = (float) B_TMPINT;

	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm
	}


void SIMUG()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm
	
#ifdef DEBUG
	printf("SIMUG - (INTEGER multiply * %u)\n", B_TMPINT);
	pause ();
#endif
	}


void SIMUC()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm
	
#ifdef DEBUG
	printf("SIMUC - (INTEGER multiply * %u)\n", B_TMPINT);
	pause ();
#endif
	}


void SIMUE()
{
	#asm
	ld	(_B_TMPINT),hl
	#endasm
	
#ifdef DEBUG
	printf("SIMUE - (INTEGER multiply * %u)\n", B_TMPINT);
	pause ();
#endif
	}


void SFMUC()
{
	#asm
	call	read1parm
	ld	hl,(_B_TMPINT)
	ld	de,_B_TMPFLOAT
	call	load_float

	ld	hl,SAC
	ld	de,_B_TMPFLOAT2
	call	load_float
	#endasm

#ifdef DEBUG
	printf("SFMUC - (FLOAT multiply %f * %f)\n", B_TMPFLOAT2, B_TMPFLOAT);
#endif

	B_TMPFLOAT = B_TMPFLOAT * B_TMPFLOAT2;

	#asm
	ld	hl,_B_TMPFLOAT
	ld	de,SAC
	call	store_float
	#endasm
	
#ifdef DEBUG
	pause ();
#endif
	}


void SFMUE()
{
#ifdef DEBUG
	printf("SFMUE - (FLOAT multiply ?)\n");
	pause ();
#endif
	}


void SPR0A()
{
// Probably this had to print a "Line feed"

#ifdef DEBUG
	printf("* ");
#endif
	}


void SPR0D()
{
	#asm
	ld	(_B_TMPINT),hl
	ld	h,d
	ld	l,e
	call	readstr
	#endasm
	
#ifdef DEBUG
	printf("SPR0D - Setup print to #%u: %s[CR]\n", B_TMPINT, B_TMPSTR);
	pause ();
#endif
	}


// Main entry - just links the "library" with the BASIC compiled object code
main()
{
	SSMAIN();
	}



// Service routines: 
// transfer and convert data from/to program memory or data areas

#asm


.readstr
	ld	c,(hl)
	inc	hl
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ld	de,_B_TMPSTR
	ld	b,0
	inc	bc
	ldir
	dec	de
	xor	a
	ld	(de),a
	ret


.read2str
	push	de
	ld	c,(hl)
	inc	hl
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ld	de,_B_TMPSTR
	ld	b,0
	inc	bc
	ldir
	dec	de
	xor	a
	ld	(de),a
	pop	de
	ld	h,d
	ld	l,e
	ld	c,(hl)
	inc	hl
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ld	de,_B_TMPSTR2
	ld	b,0
	inc	bc
	ldir
	dec	de
	xor	a
	ld	(de),a
	ret

.readjpparm
	pop	bc
	pop	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT),de
	ld	(jploc + 1),de
	push	hl
	push	bc
	ret


.read3jpparms
	pop	bc
	pop	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT),de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT2),de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT3),de
	ld	(jploc + 1),de
	push	hl
	push	bc
	ret


.read2parms
	pop	bc
	pop	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT),de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT2),de
	push	hl
	push	bc
	ret


.read1byte2parms
	pop	bc
	pop	hl
	ld	d,0
	inc	hl
	ld	e,(hl)
	ld	(_B_TMPINT3),de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT),de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	(_B_TMPINT2),de
	push	hl
	push	bc
	ret


.read1parm
	pop	bc
	pop	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	push	hl
	push	bc
	ld	(_B_TMPINT),de
	ret


; Pick float in HL (MS Basic format) and put it into DE (Z88DK format)

.load_float
	xor	a
	ld	(de),a
	inc	de
	ld	(de),a
	inc	de
	ld	bc,4
	ldir	
	ret


; Pick double precision # in HL (MS Basic format) and put it into DE (Z88DK format)

.load_double
	inc	hl
	inc	hl
	ld	bc,6
	ldir
	ret


; Move float in HL (Z88DK format) to DE (MS Basic format)

.store_float
	ld	bc,4
	inc	hl
	inc	hl
	ldir
	ret


; Move # in HL (Z88DK format) to DE (MS Basic format) in double precision 

.store_double
	ld	bc,6
	;xor	a	; we leave the extra precision bytes untouched:
	;ld	(de),a  ; no need to force them to zero because no one will use them
	inc	de
	;ld	(de),a
	inc	de
	ldir
	ret


; Copy C style string in HL to DE in BASIC format.
; The first byte holds the string lenght, then we have two bytes
; for the string location and the string itself (non terminated).

.store_string
	push	hl
	ld	bc,0
.count_loop
	ld	a,(hl)
	and	a
	jr	z,end_count
	inc	hl
	inc	c
	jr	nz,count_loop
.end_count
	ld	h,d
	ld	l,e
	ld	(hl),c
	inc	hl
	inc	de
	inc	de
	inc	de
	ld	(hl),e
	inc	hl
	ld	(hl),d
	pop	hl
	ldir
	
	ret


._DOJUMP
;	pop	hl
	pop	hl
.jploc  jp	jploc


#endasm

