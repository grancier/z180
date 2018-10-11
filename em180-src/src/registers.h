/* registers.h

   Functions to set the value of 8 or 16-bit registers. This simplifies
   the parser (emucmd.y) significantly.

   Created 1.0 on Thu Apr 17 09:15:58 BST 1997 by don
*/
#ifndef Z80_H
#include <Z80.h>
#endif

void set8 (Z80 *R, int reg, byte val);
/* Set 8-bit register to specified value. */

void set16 (Z80 *R, int reg, word val);
/* Set 16-bit register to specified value. */
