/* watch.h

   Prototype for watchpoint function. Implementation is in 'emulator.c'.
   This function is called from within 'WrZ80' to trap writes to marked
   addresses, allowing the emulator to perform watch-point tracing.

   Created on Mon May  5 21:48:07 BST 1997 by don
*/

void check_watch(register word Addr);

