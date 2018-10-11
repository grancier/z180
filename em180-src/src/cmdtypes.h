/* cmdtypes.h

   Definitions of additional (non-yacc,lex) token types and values used
   by the parser contained in emucmd.y, emucmd.lex.

   Created 1.0 on Thu Apr 17 09:15:58 BST 1997 by don
*/

#ifndef Z80_H
#include <Z80.h>
#endif

typedef struct {
  int label;
  int bits;
} Register;

typedef struct {
  int bits;
  unsigned int val;
} Number;

#define NULL_NUMBER (Number){0, 0}

/* Valid values for 'size' member of union */
#define BYTE_SIZE  1
#define SHORT_SIZE 2
#define WORD_SIZE  4

/* Rule -- register name of 1 char, or 2 chars ending in ' is 8-bits wide,
   otherwise it is 16-bits wide. */ 
extern char *regNames[];

enum REGISTERS {A,A1,F,F1,B,B1,C,C1,D,D1,E,E1,H,H1,L,L1,I,
                AF,AF1,BC,BC1,DE,DE1,HL,HL1,IX,IY,PC,SP};

