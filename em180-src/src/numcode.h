/* numcode.h
   
   Basic hexadecimal/binary input/output routines.

   Created on Thu Apr 10 11:37:01 BST 1997 by don@cs.york.ac.uk
*/

char *tohex(int i, int width, char* hex);
/* On exit, 'hex' contains the hexadecimal equivalent of the integer i
   to the specified word width (in bits). It is assumed that the buffer
   'hex' (passed in by the caller) is sufficiently large to accommodate
   the result. */

char *tobin(int i, int width, char* bin);
/* As tohex, but returns the binary form. */

int fromhex(int *i, char *hex);
/* On success, returns an integer in the '*i' argument equivalent to the
   hex value passed in.  On error, the value of the function will be
   FALSE (ie. 0). */

int frombin(int *i, char *bin);
/* As for the 'fromhex' function. */


