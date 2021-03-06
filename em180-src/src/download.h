/* download.h

   Function to read an a.out format object file generated by the cross
   compilation tools, and download it into a memory using a specified
   memory writing function.

   Created 1.0 on Fri Apr 11 17:21:53 BST 1997 by don
*/

extern char downloadErr[];  /* If download returns 0, contains the error msg. */

int download(char *fname, int baseAddr, int maxLen);
/* From the specified object file, load the text segment into the
   memory up to a maximum of 'maxLen' bytes (no maximum if maxLen<=0).
   Any errors on loading are reported via the string 'downloadErr'.
   Error is signalled by a return value of 0.*/

