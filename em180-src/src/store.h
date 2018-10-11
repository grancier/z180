/* store.h

   Implements the memory array attatched to the emulated processor.
   This consists of two areas; RAM and ROM. The initial configuration
   of the memory is set by first a call to buildMem(), followed by
   repeated calls to setBlock(). ROM areas can be loaded using
   the blow() function. The memory (not exceeding 64K) is subdivided
   into blocks of 256 Bytes. Each block can be RAM, ROM or neither.

   Memory is accessed using the RdZ80() and WrZ80() calls specified
   in Z80.h

   Created on Thu Apr 10 11:44:13 BST 1997 by don@cs.york.ac.uk
*/


void buildMem();
/* Initialises the memory data structures. Should be called before
   any other functions. */

void releaseMem();
/* Once all memory operations have been completed, call releaseMem
   to dispose of all the store used. */ 


enum MemType {RAMM=0, ROMM=1, GARBAGE=2, NONE=3};

void setMem(int addr0, int addr1, int type);
/* Sets an area of memory (resolution 256 bytes) to be either
   RAM or ROM (type RAMM, ROMM). The base address is addr0
   rounded down to the nearest multiple of 256 bytes. The finish
   address is addr1 rounded up to the nearest multiple of 256 bytes
   minus 1. */

int memType(int address);
/* Returns the type code for the memory at the specified address. */

void burn(int address, byte value);
/* Attempts to load the specified byte into memory at the given
   address. This is the only function that can modify the state
   of ROM. 'NONE' memory will not be written to. */

/* Read/write functions. */
#ifndef Z80_H
void WrZ80(register word Addr, register byte Value);
byte RdZ80(register word Addr);
#endif 
