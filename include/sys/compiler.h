

#ifndef __SYS_COMPILER_H__
#define __SYS_COMPILER_H__


/* Temporary fix to turn off features not supported by sdcc */
#ifdef Z88DK_USES_SDCC
#define __FASTCALL__
#define __CALLEE__
#define __SMALLCCALLEE __z88dk_callee
#define __SMALLCFASTCALL __z88dk_fastcall
#define __LIB__
#define __SAVEFRAME__
#define __SMALLCDECL __smallc
#define far
#else
#define __SMALLCDECL
#define __SMALLCCALLEE
#define __SMALLCFASTCALL
#endif

#define __CHAR_LF '\n'
#define __CHAR_CR '\r'


#endif
