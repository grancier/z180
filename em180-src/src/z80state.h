/* z80state.h

   Display the contents of the z80 registers.
   Format of the display is (roughly) as in figure 1-2 on p.A1-3
   of the Z80 CPU User's Manual, Zilog Inc.

   Created 1.0 on Fri Apr 11 12:11:57 BST 1997 by don
*/

char *z80state(Z80 *cpu, char *buffer);

