/* numcode.c
   
   Basic hexadecimal/binary input/output routines.
   The maximum resolution is limited to the machine word width (ie. 32 bits)

   Created on Thu Apr 10 11:37:01 BST 1997 by don@cs.york.ac.uk
*/
#include <ctype.h>
#include "types.h"
#include "numcode.h"

const char *hexdig="0123456789ABCDEF";

#define MASK1 0xFFFFFFFF

int mask(int i, int bits) { /* Masks out all but the 'bits' LSbits. */
  return (bits>=32)?i:(i & ~(MASK1 << bits));
}

char *tohex(int number, int width, char* hex) {
  int d;
  int digits;

  number = mask(number, width);	/* Remove higher-order bits. */
  digits = (width/4) + ((width%4 != 0)?1:0);
  hex[digits] = '\0';	/* String termination */
  for (d=digits-1; d>=0; d--) {  /* 0th digit is most significant */
    hex[d] = hexdig[number&0xF];
    number >>= 4;
  }
  return hex;
}
  

char *tobin(int number, int width, char* bin) {
  int d;

  number = mask(number, width);	/* Remove higher-order bits. */
  bin[width] = '\0';	/* String termination */
  for (d=width-1; d>=0; d--) {  /* 0th digit is most significant */
    bin[d] = hexdig[number&0x1];
    number >>= 1;
  }
  return bin;
}

int getdig(char code) {	/* Returns correct digit no, or -1 on failure */
  int i;
  for(i=0;i<16;i++)
    if (hexdig[i] == code) return i;
  return -1;
}

int fromhex(int *number, char *hex) {
  int i;

  *number=0;
  i=0;
  while (!isgraph(hex[i])) i++;  /* Find first printing character */
  while (isgraph(hex[i]) && (hex[i] != 'h')) {
    *number <<= 4;
    hex[i] = toupper(hex[i]);
    if ((*number += getdig(hex[i])) == -1) return 0; /* fails */
    i++;
  }
  return 1;
}
   
  
int frombin(int *number, char *bin) {
  int i, digit;

  *number=0;
  i=0;
  while (!isgraph(bin[i])) i++;  /* Find first printing character */
  while (isgraph(bin[i]) && (bin[i] != 'b')) {
    *number <<= 1;
    digit = getdig(bin[i]);
    if ((digit == 0) || (digit == 1))
      *number += digit;
    else
      return 0;
    i++;
  }
  return 1;
}
   



#ifdef TEST
/*************************************************************/
/* Stand-alone test code. */

main() {
  int i, num, rtn;
  char buffer[80];

  printf("\n\nTesting numcode routines.\n");
  printf(" 1. 'tohex(i,9,buffer)':\n ");
  for (i=254;i<259;i++) {
    printf("%d=%s  ",i,tohex(i,9,buffer));
  }
  printf("\n\n");
  printf(" 2. 'tobin(i,5,buffer)':\n ");
  for (i=13;i<17;i++) {
    printf("%d=%s  ",i,tobin(i,5,buffer));
  }
  printf("\n\n");
  printf(" 3. fromhex:\n ");
  rtn = fromhex(&num, "8024");
  printf("fromhex(&num, \"8024\") = %d, num = %d\n\n",rtn, num);
  
  printf(" 3a. fromhex:\n ");
  rtn = fromhex(&num, "8024h");
  printf("fromhex(&num, \"8024h\") = %d, num = %d\n\n",rtn, num);

  printf(" 4. frombin:\n ");
  rtn = frombin(&num, "1101101");
  printf("frombin(&num, \"1101101\") = %d, num = %d\n\n",rtn, num);

  printf(" 4a. frombin:\n ");
  rtn = frombin(&num, "1101101b");
  printf("frombin(&num, \"1101101b\") = %d, num = %d\n\n",rtn, num);

  printf("All tests complete. Bye. \n\n");
} 
/************************************************************/
#endif
