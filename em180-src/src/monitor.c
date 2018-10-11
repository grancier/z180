/* monitor.c

   Hexadecimal memory monitor. Given a start location, a number of bytes,
   word length and endian-ness, fills a string buffer with a representation
   of the memory stored therein. The user must supply a memory read
   function.

   Created 1.0 on Fri Apr 11 10:28:07 BST 1997 by don@cs.york.ac.uk
*/
#include <stdio.h>
#include "types.h"
#include "terminal.h"
#include "numcode.h"
#include "monitor.h"

int wordsperline(int addrLength, int wordLength) {
  /* A word is 2*wordLength characters long. */
  /* Add to this the space for a character map, makes 3*wordLength */

  return (TERMWIDTH - (2*addrLength+2))/(3*wordLength+2);
}


char *toword(int word, int wordLength, int littleEndian, char *buf) {
/* Converts word into a little/big endian representation of the
   specified length. */

  if (littleEndian || (wordLength==1)) {
    return tohex(word, wordLength*8, buf);
  } else {
    int bptr, byte;
    char str[TERMWIDTH];

    bptr = 0;
    for(byte=0;byte<wordLength;byte++) {
      bptr += sprintf(&buf[bptr], "%s", tohex(word&0xFF, 8, str));
      word >>= 8;
    }
    return buf;
  }
}


char *monitor(int start, int bytes,
              int addrLength, int wordLength, int littleEndian,
              byte (*read)(int address),
              char *buffer) {
  int wpl, bpl, lines, addrBits;
  int i, word, wordVal, line, linebase, bptr;
  char buf[TERMWIDTH];
  char row[TERMWIDTH];

  {				/* Compute wpl, lines, addrbits */
    int words;
    wpl = wordsperline(addrLength, wordLength);
    bpl = wpl * wordLength;
    words = (bytes/wordLength) + ((bytes%wordLength != 0)?1:0);
    lines = (words/wpl) + ((words%wpl != 0)?1:0);
    if (addrLength>4) addrLength=4;
    if (addrLength<2) addrLength=2;	/* Defaults to 16-bit address */
    if (wordLength>4) wordLength=4;
    if (wordLength<1) wordLength=1;	/* Defaults to 1-byte words */
    addrBits=addrLength*8;
  } 

  if (lines > TERMHEIGHT) lines = TERMHEIGHT;

  bptr=0;
  for (line=0; line<lines; line++) {
    linebase = start + (line*bpl);
    for (i=0;i<bpl;i++) row[i] = (*read)(linebase + i); /* Local buffer */
    bptr += sprintf(&buffer[bptr], "%s: ", tohex(linebase, addrBits, buf));
    for (word=0; word<wpl; word++) {
      wordVal = 0;
      for(i=wordLength-1;i>=0;i--) {	/* Read in as little-endian */
        wordVal <<= 8;
        wordVal += (int)(row[word*wordLength+i]);
      }
      bptr += sprintf(&buffer[bptr], "%s ",
                      toword(wordVal, wordLength, littleEndian, buf));
    }
    bptr += sprintf(&buffer[bptr], "  ");
    for(i=0;i<bpl;i++) {
      if ((row[i] >= 32) && (row[i] <= 127))
        bptr += sprintf(&buffer[bptr], "%c", row[i]);
      else
        bptr += sprintf(&buffer[bptr], ".");
    }
    bptr += sprintf(&buffer[bptr], "\n");
  }
  return buffer;
}



#ifdef TEST
/*************************************************************/
/* Stand-alone test code */
byte rd(int address) {
  return (byte)(((address<<4)&0xF0)|((address>>4)&0xF));
}

void main() {
  char buffer[MINBUFFLEN];

  printf("\n\nTesting Monitor\n");
  printf("\n1. 79 bytes as bytes:\n%s\n",
         monitor(0, 79, 2, 1, 1, rd, buffer));
  printf("\n2. 79 bytes as little-endian 2-byte words:\n%s\n",
         monitor(0, 79, 2, 2, 1, rd, buffer));
  printf("\n3. 79 bytes as big-endian 2-byte words:\n%s\n",
         monitor(0, 79, 2, 2, 0, rd, buffer));
  printf("\n4. 79 bytes as little-endian 4-byte words:\n%s\n",
         monitor(0, 79, 2, 4, 1, rd, buffer));
  printf("\n5. 79 bytes as big-endian 4-byte words:\n%s\n",
         monitor(0, 79, 2, 4, 0, rd, buffer));
  printf("End of tests... Bye!\n\n");
}
/*************************************************************/
#endif

