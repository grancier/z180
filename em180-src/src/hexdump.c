/* hexdump.c

   Hexadecimal file dumping utility. Simply reads from the start of
   a file and dumps what it finds to stdout.

   Created 1.0 on Fri Apr 11 15:55:27 BST 1997 by don
*/
#include <stdlib.h>
#include <stdio.h>
#include "terminal.h"
#include "types.h"
#include "monitor.h"

static byte buffer[TERMWIDTH];
static int valid;
static int base;

byte read(int addr) {
  if ((addr - base) < valid)
    return buffer[(addr - base)];
  else
    return (byte)0xFF;
}

main(int argc, char *argv[]) {
  FILE *file;
  int linelen;
  int addr, c;
  char linebuf[TERMWIDTH];

  if (argc < 2) {
    printf("Usage: hexdump <filename>\n");
    exit(0);
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Cannot open file <%s> for reading!\n");
    exit(1);
  }

  linelen = wordsperline(2, 1);	/* 4byte address, 1byte words. */
 
  addr = 0;
  base = 0;
  valid = 0; 
  while ((c = fgetc(file)) != EOF) {
    buffer[(addr-base)] = (byte)c;
    valid++; addr++;
    if (valid == linelen) {
      printf("%s", monitor(base, valid, 4, 1, 0, read, linebuf));
      valid = 0;
      base = addr;
    }
  }
  if (valid > 0)
    printf("%s", monitor(base, valid, 4, 1, 0, read, linebuf));

  fclose(file);
}
