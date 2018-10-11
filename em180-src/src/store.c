/* store.c

   Implements the memory array attatched to the emulated processor.
   Assumes 'int' is 32-bits, and that 'malloc' returns blocks
   aligned *at least* on 4-byte boundaries.

   Last modified on Mon May  5 16:46:02 BST 1997 by don
   Created on Thu Apr 10 11:44:13 BST 1997 by don@cs.york.ac.uk
*/
#include <stdlib.h>
#include <memory.h>
#include "types.h"
#include "store.h"
#include "watch.h"

#define MEMSIZE 65536
#define BLOCKSIZE 256
#define BLOCKSHIFT 8
#define BLOCKMASK 0xFF
#define BLOCKS MEMSIZE/BLOCKSIZE
#define PTRMASK  0xFFFFFFFC	/* Last 2 bits contains Blocktype. */
#define TYPEMASK 0x00000003

#ifndef TRUE
#define TRUE (1==1)
#define FALSE !(TRUE)
#endif

char *blockPtr[BLOCKS];

void buildMem() {	/* Initialises blockPtr structure. */
  int i;

  for(i=0;i<BLOCKS;i++) 
    blockPtr[i] = (byte *)NONE;
}

void releaseMem() {	/* Releases all non-'NONE' blocks in memory. */
  int i;
 
  for(i=0;i<BLOCKS;i++)
    if (((int)blockPtr[i] & TYPEMASK) != NONE)
      free((byte *)((int)blockPtr[i] & PTRMASK));
}

void setMem(int addr0, int addr1, int type) {
  int block0, block1, i;

  /* Validate parameters */
  if ((addr1 < addr0) || (addr1 < 0)) return;
  if (addr1 > (MEMSIZE-1)) addr1 = MEMSIZE-1;
  if ((type & TYPEMASK) == GARBAGE) return;
  block0 = addr0/BLOCKSIZE; 
  block1 = addr1/BLOCKSIZE;
  for (i=block0;i<=block1;i++) {
    if (type == NONE) {
      if (((int)blockPtr[i] & PTRMASK) != NULL) {
        free(blockPtr[i]);
        blockPtr[i] = NULL;
      }
    } else {
      if (((int)blockPtr[i] & PTRMASK) == NULL)
        blockPtr[i] = (byte *)malloc(BLOCKSIZE);
      (int)blockPtr[i] &= PTRMASK;
      (int)blockPtr[i] |= (type & TYPEMASK);
    }
  }
}

int memType(int address) {
  return (int)blockPtr[address/BLOCKS] & TYPEMASK;
}


void burn(int address, byte value) { /* writes to RAM or ROM */
  int block;
  int offset;

  block = address >> BLOCKSHIFT;
  offset = address & BLOCKMASK;

  if (((int)blockPtr[block] & TYPEMASK) != NONE)  /* Writable RAM/ROM */
      *(byte *)(((int)blockPtr[block]&PTRMASK)+offset) = value;
}

/******************************************************************/
/* Write/Read required by Z80 emulator code */
void WrZ80(register word Addr, register byte Value) {
  register int block;
  register int offset;
  
  check_watch(Addr);  /* Checks for hitting watchpoint. */

  block = Addr >> BLOCKSHIFT;
  offset = Addr & BLOCKMASK;

  if (((int)blockPtr[block] & TYPEMASK) == RAMM)
    *(byte *)(((int)blockPtr[block]&PTRMASK)+offset) = Value;
}


byte RdZ80(register word Addr) {
  register int block;
  register int offset;
  
  check_watch(Addr);  /* Checks for hitting watchpoint. */

  block = Addr >> BLOCKSHIFT;
  offset = Addr & BLOCKMASK;
  if (((int)blockPtr[block] & TYPEMASK) != NONE) { /* ie. RAM or ROM */
    return *(byte *)(((int)blockPtr[block]&PTRMASK)+offset);
  } else {
    return (byte)0xFF;   /* ie. crap - but assume TTL float high */
  }
}

