/* monitor.h

   Hexadecimal memory monitor. Given a start location, a number of bytes,
   word length and endian-ness, fills a string buffer with a representation
   of the memory stored therein. The user must supply a memory read
   function. Note: the endianness flag only applies to the data, not
   the address display.

   Created 1.0 on Fri Apr 11 10:28:07 BST 1997 by don@cs.york.ac.uk
*/
#define MINBUFFLEN 1024

/* Useful for external formatting. Returns the number of words
   on a line that the 'monitor' function will return. */
int wordsperline(int addrLength, int wordLength);        

/* addrLength, wordLength are expressed in bytes. */
char *monitor(int start, int bytes,
              int addrLength, int wordLength, int littleEndian,
              byte (*read)(int address),
              char *buffer);
    
