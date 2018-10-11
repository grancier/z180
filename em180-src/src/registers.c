/* registers.c

   Enumeration identifying all the registers in the Z80 CPU. Also,
   functions to set the value of 8 or 16-bit registers. This simplifies
   the parser (emucmd.y) significantly.

   Created 1.0 on Thu Apr 17 09:15:58 BST 1997 by don
*/
#include <stdlib.h>
#include <Z80.h>
#include "registers.h"
#include "cmdtypes.h"


void set8 (Z80 *R, int reg, byte val) {
  if (R == NULL) return;
  switch (reg) {
    case A: 	R->AF.B.h  = val; break;
    case A1: 	R->AF1.B.h = val; break;
    case F: 	R->AF.B.l  = val; break;
    case F1: 	R->AF1.B.l = val; break;
    case B: 	R->BC.B.h  = val; break;
    case B1: 	R->BC1.B.h = val; break;
    case C: 	R->BC.B.l  = val; break;
    case C1: 	R->BC1.B.l = val; break;
    case D: 	R->DE.B.h  = val; break;
    case D1: 	R->DE1.B.h = val; break;
    case E: 	R->DE.B.l  = val; break;
    case E1: 	R->DE1.B.l = val; break;
    case H: 	R->HL.B.h  = val; break;
    case H1: 	R->HL1.B.h = val; break;
    case L: 	R->HL.B.l  = val; break;
    case L1: 	R->HL1.B.l = val; break;
    case I: 	R->I       = val; break;
    default: break;
  }
}

void set16 (Z80 *R, int reg, word val) {
  if (R == NULL) return;
  switch (reg) {
    case AF: 	R->AF.W  = val; break;
    case AF1: 	R->AF1.W = val; break;
    case BC: 	R->BC.W  = val; break;
    case BC1: 	R->BC1.W = val; break;
    case DE: 	R->DE.W  = val; break;
    case DE1: 	R->DE1.W = val; break;
    case HL: 	R->HL.W  = val; break;
    case HL1: 	R->HL1.W = val; break;
    case IX: 	R->IX.W  = val; break;
    case IY: 	R->IY.W  = val; break;
    case PC: 	R->PC.W  = val; break;
    case SP: 	R->SP.W  = val; break;
    default: break;
  }
}


