/* z80state.c

   Display the contents of the z80 registers.

   Created 1.0 on Fri Apr 11 12:11:57 BST 1997 by don
*/
#include <stdio.h>
#include <Z80.h>
#include "terminal.h"
#include "types.h"
#include "numcode.h"
#include "z80state.h"

char *z80state(Z80 *cpu, char *b) {
  int bp;
  char b1[20],b2[20],b3[20],b4[20],b5[20],b6[20];

  if (cpu == NULL) return NULL;
#define bin "11010110"
#define h2 "DA"
#define h4 "DEAD"

  bp = 0;
  /* I, IX, IY, PC, SP */
  bp += sprintf(&b[bp], "I:%s IX:%s IY:%s PC:%s SP:%s\n",
		tohex(cpu->I,8,b1),
                tohex(cpu->IX.W,16,b2), tohex(cpu->IY.W,16,b3),
                tohex(cpu->PC.W,16,b4), tohex(cpu->SP.W,16,b5));
  bp += sprintf(&b[bp], "------------------------------------\n");
  /* AF, BC, DE, HL */
  bp += sprintf(&b[bp], "                            SZ H PNC\n");
  bp += sprintf(&b[bp], "A:  %s %s      F:  %s %s\n",
                tohex(cpu->AF.B.h,8,b1), tobin(cpu->AF.B.h,8,b2), 
                tohex(cpu->AF.B.l,8,b3), tobin(cpu->AF.B.l,8,b4));
  bp += sprintf(&b[bp], "BC:  %s %s   DE:  %s %s   HL:  %s %s\n",
                tohex(cpu->BC.B.h,8,b1), tohex(cpu->BC.B.l,8,b2),
                tohex(cpu->DE.B.h,8,b3), tohex(cpu->DE.B.l,8,b4),
                tohex(cpu->HL.B.h,8,b5), tohex(cpu->HL.B.l,8,b6));
  bp += sprintf(&b[bp], "------------------------------------\n");
  /* AF', BC', DE', HL' */
  bp += sprintf(&b[bp], "                            SZ H PNC\n");
  bp += sprintf(&b[bp], "A': %s %s      F': %s %s\n",
                tohex(cpu->AF1.B.h,8,b1), tobin(cpu->AF1.B.h,8,b2), 
                tohex(cpu->AF1.B.l,8,b3), tobin(cpu->AF1.B.l,8,b4));
  bp += sprintf(&b[bp], "BC': %s %s   DE': %s %s   HL': %s %s\n",
                tohex(cpu->BC1.B.h,8,b1), tohex(cpu->BC1.B.l,8,b2),
                tohex(cpu->DE1.B.h,8,b3), tohex(cpu->DE1.B.l,8,b4),
                tohex(cpu->HL1.B.h,8,b5), tohex(cpu->HL1.B.l,8,b6));

  return b;
}






#ifdef TEST
/*****************************************************************/
/* Stand-alone test code */
main() {
  Z80 *cpu;
  char buffer[1024];

  cpu = (Z80 *)malloc(sizeof(Z80));

  printf("\n\nBeginning test...\n\n");
  printf("%s\n", z80state(cpu, buffer));
  printf("End of test. Bye! \n\n"); 
}
/*****************************************************************/
#endif


