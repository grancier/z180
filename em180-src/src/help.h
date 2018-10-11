/* help.h

   Help screen and further information texts. Used by the 'help' function
   implemented in 'emulator.c'. This corresponds with the commands defined
   by the grammar in 'emucmd.y'.

   Created on Tue Apr 22 13:59:51 BST 1997 by don
*/

#include "emucmd.tab.h"

struct TabEntry {
  int cmd;
  char *text;
}helptab[] = {
 {   0,
   "64180 Emulator:\n-------------\n"
   "The emulator simulates a simple 64180-based microprocessor system,\n"
   "consisting of a 64180 CPU, optional sections of RAM and ROM, and\n"
   "optional serial ports.\n"
   "Using the emulator, you can define the memory layout of the system\n"
   "and can then write and run programs in 64180 machine language.\n"
   "The emulator allows the state of the CPU registers and memory\n"
   "to written and examined, program code to be loaded from a linked\n"
   "object-code file, the processor to be single stepped, and\n"
   "breakpoint execution to be performed.\n\n"
   "Where required in commands, two numeric formats are supported;\n"
   "binary and hexadecimal. A binary number is suffixed with 'b',\n"
   "and a hexadecimal number is suffixed with 'h'.\n\n"
   "For further help, type 'help' or '?' suffixed by one of the\n"
   "following command names:\n\n"
   "help\treset\tdisplay\tinterrupt\n"
   "load\tset\tstep\tbreak\n"
   "mem\tdis\texit\tRAM\n"
   "ROM\twatch\tclear\tshow\n"
 },
 {HELP,
   "help (abbr '?'):\n----------------\n"
   "usage:\thelp\n\thelp <command name>\n\n"
   "The 'help' command gives online help for all of the commands\n"
   "recognised by the emulator. For general help, simply type\n" 
   "'help' or '?' at the command prompt. For help on a particular\n"
   "command, type 'help <command name>'. To obtain a list of command\n"
   "names, simply type 'help'.\n"
 },
 {EXIT,
   "exit (abbr 'x'):\n---------------\n"
   "usage:\texit\n\n"
   "Stop the emulation session. All unsaved information will be lost.\n"
   "Currently there are no facilities for storing any emulator state\n"
   "between sessions.\n"
 },
 {RESET,
   "reset (abbr 'r'):\n-----------------\n"
   "usage:\treset\n"
   "Sets the state of all machine registers to their initial state,\n"
   "equivalent to applying a reset signal to the CPU.\n"
 },
 {DISPLAY,
   "display (abbr 'd'):\n-------------------\n"
   "usage:\tdisplay\n\n"
   "Display the state of all CPU registers.\n"
 },
 {SET,
   "set:\n----\n"
   "usage:\tset addr1\n"
	 "\t value\n"
         "\tset addr1 [addr2] value\n"
         "\tset register value\n\n"
   "The set command is used to write values into areas of RAM (once\n"
   "created using the RAM command), or to set the values stored in\n"
   "registers. The first form initialises a writing pointer.\n"
   "After initialising the pointer, commands consisting of simple\n"
   "values will result in the values being written to successive\n"
   "memory locations, advancing the pointer as required. This provides\n"
   "a rapid mechanism for writing values (such as hand-assembled code)\n"
   "into memory. When writing to memory, 8-32 bit words can be specified.\n"
   "Multi-byte words are stored in little-endian byte order.\n"
   "When writing to registers, the word size and register size must\n"
   "match. The valid register names are:\n"
   "\tA,A',F,F',B,B',C,C',D,D',E,E',H,H',L,L',I (8 bit)\n"
   "\tAF,AF',BC,BC',DE,DE',HL,HL',IX,IY,PC,SP (16 bit)\n"
   "Examples:\n"
   "\t set 0100h\n"
   "\t\t set the memory write pointer to 0100h.\n"
   "\t 01A3h"
   "\t\t write the value 01A3h to the memory at the write pointer\n"
   "\t\t and advance the write pointer by 2 bytes.\n"
   "\t set 0100h 2AFEh\n"
   "\t\t set the 16-bit word starting at byte 0100h to 2AFEh\n"
   "\t set 0100h 0200h CDh\n"
   "\t\t set each byte in the address range to CDh\n"
   "\t set AF 1011010110100000b\n"
   "\t\t set register pair AF to the specified bit pattern\n\n"
   "In the 64180 emulator, you can also use the following extra\n"
   "set instructions:\n"
   "\t set max <instruction limit>\n"
   "\t\t sets the maximum number of instructions run at once by \"run\"\n"
   "\t\t to the user specified value. Default: 10000\n"
   "\t set sbcmode\n"
   "\t\t turn on Single Board Computer emulation. The internal 64180\n"
   "\t\t extended registers are emulated, and serial port emulation\n"
   "\t\t is switched on.\n\n"
 },
 {RAM,
   "RAM/ROM:\n--------\n"
   "usage:\tRAM addr1 addr2\n"
         "\tROM addr1 addr2\n"
   "Designate the area of memory including the two addresses to be\n"
   "RAM or ROM. The memory is divided into 256 byte blocks, hence the\n"
   "blocks containing both addresses, and the intervening blocks will\n"
   "all be set to the appropriate type.\n"
 },
 {LOAD,
   "load (abbr 'l'):\n----------------\n"
   "usage:\tload file address\n"
   "Load the non-relocatable object file `file' into memory starting\n"
   "at address `address'. This can write to both RAM and ROM areas of\n"
   "memory.\n"
 },
 {MEMORY,
   "mem (abbr 'm'):\n---------------\n"
   "usage:\tmem [addr1 [addr2]] [{b|s|w}]\n"
   "Display an area of memory on the screen. If specified, the addresses\n"
   "give the beginning and end of the area to be displayed. If no address\n"
   "is specified, the area immediately before and after the stack pointer\n"
   "(SP) will be displayed. The optional size specifier designates whether\n"
   "the memory is displayed as bytes, shorts (16 bits) or words (32 bits).\n"
   "shorts/words are read in little-endian byte order.\n"
 },
 {DISASSEMBLE,
   "dis:\n----\n"
   "usage:\tdis [addr1 [addr2]]\n"
   "Disassemble the memory in the specified address range. If no second\n"
   "address is specified, a small number of bytes after the first address\n"
   "are disassembled. If no first address is given, then the disassembly\n"
   "proceeds from the current value of the program counter register (PC).\n"
 },
 {STEP,
   "step (abbr '.'):\n----------------\n"
   "usage:\tstep\n"
   "Execute the next instruction to be fetched by the CPU.\n"
 },
 {RUN,
   "run:\n----\n"
   "usage:\trun [addr]\n"
   "Run the CPU, either from the specified value for the program counter\n"
   "or from its current value if none is specified. Execution will be\n"
   "stopped by one of three things; accessing memory inside a designated\n"
   "watch range, being about to execute an instruction at a breakpoint,\n"
   "or having executed 10K instructions since the 'run' command was\n"
   "issued.\n"
 },
 {BREAK,
   "break (abbr 'br'):\n------------------\n"
   "usage:\tbreak addr\n"
   "Set a breakpoint at the specified address. When executing code, if the\n"
   "CPU is about to execute the instruction at the specified address, then\n"
   "the emulator will interrupt execution to allow the user to examine the\n"
   "state of the system.\n"
 },
 {WATCH,
   "watch (abbr 'w'):\n-----------------\n"
   "usage:\twatch addr1 [addr2]\n"
   "Set a watch range between the specified addresses. If addr2 is not\n"
   "specified, then it is taken to be the same as addr1. If during execution\n"
   "a read/write is attempted to an address in the specified range, the\n"
   "emulator will interrupt execution immediately after the instruction cycle\n"
   "on which the write ocurred.\n"
 },
 {CLEAR,
   "clear (abbr 'c'):\n-----------------\n"
   "usage:\tclear break\n"
         "\tclear watch\n"
   "Clear either all currently set breakpoints, or all currently set\n"
   "watch ranges.\n"
 },
 {SHOW,
   "show (abbr 'sh'):\n-----------------\n"
   "usage:\tshow\n"
   "Display the currently set breakpoints and watch ranges.\n"
 },
 {INTERRUPT,
   "interrupt (abbr 'int'):\n-----------------------\n"
   "usage:\tinterrupt [vector]\n"
   "Causes the processor to respond to the specified interrupt (NMI\n"
   "if none specified) during the next CPU cycle. The processor\n"
   "will not respond to a maskable interrupt (vector not 0066h) if the\n"
   "IFF flag is not set. The state of the IFF flag can be manipulated\n"
   "directly using the the EI and DI instructions (FBh and F3h).\n"
 },
 {  -1, ""}
};
