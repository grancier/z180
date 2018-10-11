/* disass.c

   Front-end for the emulator library disassembler, providing
   a disassembly listing of a portion of memory.

   Created 1.0 on Fri Apr 11 14:52:33 BST 1997 by don
*/
#include <stdio.h>
#include "types.h"
#include "terminal.h"
#include "numcode.h"
#include "disass.h"

extern int DAsm(char *S, byte *A);

char *disass(int start, int stop, byte (*read)(int address), char *buffer) {
  int i,bptr,inslen,line;
  char b1[20],b2[20],ins[20];
  byte text[4];	/* Read-ahead buffer */
   
  bptr = 0;
  line = 0;
  while ((start < stop) || (stop == -1)) {
    for(i=0;i<4;i++) text[i] = (*read)(start+i);  /* Load read-ahead buffer */
    inslen = DAsm(ins, text);  /* Disassemble 1 instruction */
    bptr += sprintf(&buffer[bptr], "%s: ", tohex(start, 16, b1));
    for(i=0;i<inslen;i++)
      bptr += sprintf(&buffer[bptr], " %s", tohex(text[i],8,b1));
    bptr += sprintf(&buffer[bptr], "\t %s", ins);
    bptr += sprintf(&buffer[bptr], "\n");
    start += inslen;
    if (line++ > (TERMHEIGHT-3)) break;
    if (stop == -1) break;
  }
  return buffer;
}




#ifdef TEST
/********************************************************************/
/* Stand-alone test code */
const byte data[] = {1, 147, 29, 31, 0xCB, 70, 87, 9, 94, 95, 134, 205};
byte rd(int address) {
  return data[address % sizeof(data)];
}

main() {
  char buffer[1024];

  printf("\n\nTesting disassembler function:\n\n");
  printf("%s\n", disass(0, sizeof(data)-1, rd, buffer));
  printf("End of test. Bye!\n\n");
}
/********************************************************************/
#endif
