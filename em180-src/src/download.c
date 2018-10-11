/* download.c

   Function to read an a.out format object file generated by the cross
   compilation tools, and download it into a memory using the 'burn'
   function from 'store.h'.

   Last modified on Sun Feb  3 17:05:52 GMT 2002 by jdw
   Last modified on Mon May 12 14:20:26 BST 1997 by don
   Created 1.0 on Fri Apr 11 17:21:53 BST 1997 by don
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* #include "/sys/src/cmd/cross/include/a.out.h" */
#include "../include/a.out.h"		/* jdw: this is the a.out.h file */
									/* from the H180 cross compiler */
#include "terminal.h"
#include "types.h"
#include "store.h"
#include "download.h"

char downloadErr[TERMWIDTH];

int download(char *fname, int baseAddr, int maxLen) {
  FILE *objFile;		/* This could be heavily optimised... */
  struct exec objHdr;
  int textLen, i;
  int data;

  strcpy(downloadErr,"Ok.");	/* Clear error reporting mechanism */

  objFile=fopen(fname, "r");
  if (objFile == NULL) {	/* Opened file ok? */
    sprintf(downloadErr, "Cannot open <%s> for reading!", fname);
    return 0;
  }

  /* Attempt to read header. If cannot read all bytes, fails. */
  if (fread((void *)&objHdr,1,sizeof(struct exec), objFile) !=
            sizeof(struct exec)) {
    sprintf(downloadErr, "Object file <%s> header read failure!", fname);
    return 0;
  }

  /* jdw: The a.out files generated by the H180 compiler are always
   * big-endian. On Intel systems, we need to swap the byte order of
   * the header. */
#ifdef LSB_FIRST

#define SWAP_WORD_ENDIANNESS(x) \
  			{ \
				char temp ; \
				temp = ( (char *) (x) )[ 0 ] ; \
				( (char *) (x) )[ 0 ] = ( (char *) (x) )[ 3 ] ; \
				( (char *) (x) )[ 3 ] = temp ; \
				temp = ( (char *) (x) )[ 1 ] ; \
				( (char *) (x) )[ 1 ] = ( (char *) (x) )[ 2 ] ; \
				( (char *) (x) )[ 2 ] = temp ; \
			} 

  SWAP_WORD_ENDIANNESS ( & objHdr . a_magic ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_text ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_data ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_bss ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_syms ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_entry ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_trsize ) ;
  SWAP_WORD_ENDIANNESS ( & objHdr . a_drsize ) ;
#endif

  
  /* Decode header. Look for correct magic number (0407) */
  if (N_BADMAG(objHdr)) {
    sprintf(downloadErr, "Object file <%s> bad magic", fname);
    return 0;
  }
 
  /* Locate to start of text segment */
  if (fseek(objFile,N_TXTOFF(objHdr),SEEK_SET) != 0) { 
    sprintf(downloadErr, "Object file <%s>. Cannot find text!", fname);
    return 0;
  }
  
  /* Download text segment into memory. Choose smaller of size & maxLen */
  textLen = ((maxLen > 0)&&(maxLen<objHdr.a_text))?maxLen:objHdr.a_text;
  for(i=0;i<textLen;i++) {
    if ((data = fgetc(objFile)) == EOF) {
      sprintf(downloadErr, "Object file <%s>. Unexpected EOF!", fname);
      return 0;
    }
    burn(baseAddr+i,(byte)data);
  }

  fclose(objFile);
  return i; 	/* Number of bytes loaded. */
}




#ifdef TEST
/***************************************************************/
/* Stand-alone test code. */
#include "monitor.h"

#define MAXLEN 80
char mem[MAXLEN];

void wr(int addr, byte val) {
  mem[addr%MAXLEN] = val;
}

byte rd(int addr) {
  return mem[addr%MAXLEN];
}

void main(int argc, char *argv[]) {

  char buffer[80];
  int loaded;

  printf("\n\nTesting download function...\n");
  if (argc < 2) {
    printf("Usage: loadtest <object filename>\n\n");
    exit(0);
  }

  if ((loaded = download(argv[1], 0, MAXLEN, wr)) == 0) {
    printf("Error: %s\n", downloadErr);
  } else {
    printf("%s", monitor(0, loaded, 2, 1, 0, rd, buffer));
  }

  printf("\nTesting finished. Bye!!\n");
}
/***************************************************************/
#endif


