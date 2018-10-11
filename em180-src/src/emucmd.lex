/* emucmd.lex */
/* Scanner for Z80 Emulator */
/* Version 2.1 - less case sensitive Sun Feb  3 19:31:35 GMT 2002 by jdw */
/* Version 2.0 Fri Apr 18 10:51:18 BST 1997 by don */
/* Created 1.0 on Wed Apr 16 09:00:19 BST 1997 by don */

%{
#include <string.h>
#include "cmdtypes.h"
#include "emucmd.tab.h"
#include "registers.h"
#include "numcode.h"
%}

HEXDIG	[0-9A-Fa-f]
BINDIG	[0-1]

%%

{HEXDIG}+h	{
                  if (fromhex(&(yylval.val.val), yytext) == 0)
                    return BAD_VALUE;
                  else {
                    yylval.val.bits = (strlen(yytext)-1)*4;
                    return VALUE;
                  }
		}

{BINDIG}+b      {
                  if (frombin(&(yylval.val.val), yytext) == 0)
                    return BAD_VALUE;
                  else {
                    yylval.val.bits = (strlen(yytext)-1);
                    return VALUE;
                  }
                }

b(yte(s)?)?	{ yylval.size=BYTE_SIZE; return SIZE_TAG; }
s(hort(s)?)?	{ yylval.size=SHORT_SIZE; return SIZE_TAG; }
w(ord(s)?)?	{ yylval.size=WORD_SIZE; return SIZE_TAG; }


\?|help		return HELP;
x|quit|q|exit		return EXIT;
r(eset)?	return RESET;
d(isplay)?	return DISPLAY;
set		return SET;
ram|RAM		return RAM;
rom|ROM		return ROM;
l(oad)?		return LOAD;
m(em)?		return MEMORY;
dis		return DISASSEMBLE;
\.|step		return STEP;
run		return RUN;
br(eak)?	return BREAK;
w(atch)?	return WATCH;
c(lear)?	return CLEAR;
sh(ow)?		return SHOW;
int(errupt)?	return INTERRUPT;
sbcmode		return SBCMODE;
max|MAX		return MAX;

([a-z]|[A-Z])([a-z]|[A-Z])?\'?	{
                  int i;
                  for(i=0;*regNames[i] != '*';i++) {
                    if (strcasecmp(yytext,regNames[i]) == 0) {
                      yylval.reg.label = i;
                      if (yytext[strlen(yytext)-1] == '\'')
                        yylval.reg.bits = (strlen(yytext)-1)*8;
                      else
                        yylval.reg.bits = strlen(yytext)*8;
                      return REGISTER;
                    }
                  }
                  return BAD_REGISTER;
                }

[ /t]+		/* Eat whitespace */
[a-zA-Z0-9\.]+	{
		  strcpy(yylval.str, yytext);
                  return STRING;
		}
\n		return '\n';
%%

/* This must match with the code in cmdtypes.h, and registers.c */
char *regNames[] = {
  "A","A\'","F","F\'","B","B\'","C","C\'",
  "D","D\'","E","E'","H","H\'","L","L\'","I",
  "AF","AF\'","BC","BC\'","DE","DE\'","HL","HL\'","IX","IY","PC","SP","*"
};

/* Indicate that normal wrap-up should continue (man lex) */
int yywrap(void) {return 1;}


#ifdef TEST
/**************************************************************************/
/* Stand-alone test code */
YYSTYPE yylval;
main() {
  for (;;) {
    int x;
    x = yylex();
    printf("got token %d\n", x);
  }
}
#endif

