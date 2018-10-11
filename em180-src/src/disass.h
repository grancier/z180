/* disass.h

   Front-end for the emulator library disassembler, providing
   a disassembly listing of a portion of memory.

   Created 1.0 on Fri Apr 11 14:52:33 BST 1997 by don
*/

char *disass(int start, int stop, byte (*read)(int address), char *buffer);

