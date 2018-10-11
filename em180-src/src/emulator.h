/* emulator.h

   Command-line interpreter functions to run the emulator. This is
   an interface between the grammar contained in emucmd.y and the
   functions actually implementing the emulator. The functionality
   placed here greatly reduces the complexity of emucmd.y.

   The functions report any errors to stdout.

   Created 1.0 on Fri Apr 18 11:51:33 BST 1997 by don
*/

/* Definitions for the emulator as a whole */
extern char *banner;
extern char *prompt;

int init_emulator();
int reset();
int help(int cmd);
int display();
int step();
int call_exit();
int interrupt(Number vector);
int build_mem(int type, Number addr1, Number addr2);
int set_mem(Number addr1, Number addr2, Number value);
int set_register(Register reg, Number value);
int display_memory(Number addr1, Number addr2, int size);
int disassemble_memory(Number addr1, Number addr2);
int load_object(char *fname, Number addr);
int run(Number entry);
int set_break(Number addr);
int clear_break();

