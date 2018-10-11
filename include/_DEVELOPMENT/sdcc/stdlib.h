
// automatically generated by m4 from headers in proto subdir


#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>
#include <stdint.h>

// DATA STRUCTURES

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int  size_t;
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned char wchar_t;
#endif

#ifndef _FLOAT_T_DEFINED
#define _FLOAT_T_DEFINED

   #ifdef __CLANG
   
   typedef float float_t;
   
   #endif

   #ifdef __SDCC
   
   typedef float float_t;
   
   #endif
   
   #ifdef __SCCZ80
   
   typedef double float_t;
   
   #endif
   
#endif

#ifndef _DOUBLE_T_DEFINED
#define _DOUBLE_T_DEFINED

   #ifdef __CLANG
   
   typedef float double_t;
   
   #endif

   #ifdef __SDCC
   
   typedef float double_t;
   
   #endif
   
   #ifdef __SCCZ80
   
   typedef double double_t;
   
   #endif
   
#endif

typedef struct
{

   int rem;
   int quot;

} div_t;

typedef struct
{

   unsigned int rem;
   unsigned int quot;

} divu_t;

typedef struct
{

   long quot;
   long rem;

} ldiv_t;

typedef struct
{

   unsigned long quot;
   unsigned long rem;

} ldivu_t;

#ifdef __CLANG

   typedef struct
   {
      long long rem;
      long long quot;
   
   } lldiv_t;

   typedef struct
   {
      unsigned long long rem;
      unsigned long long quot;

   } lldivu_t;

#endif

#ifdef __SDCC

   typedef struct
   {
      long long rem;
      long long quot;
   
   } lldiv_t;

   typedef struct
   {
      unsigned long long rem;
      unsigned long long quot;

   } lldivu_t;

#endif

#ifndef NULL
#define NULL            ((void*)(0))
#endif

#define EXIT_FAILURE    0
#define EXIT_SUCCESS    1

#define RAND_MAX        32767

#define MB_CUR_MAX      1

#define FTOA_FLAG_PLUS  0x40
#define FTOA_FLAG_SPACE 0x20
#define FTOA_FLAG_HASH  0x10

#define DTOA_FLAG_PLUS  0x40
#define DTOA_FLAG_SPACE 0x20
#define DTOA_FLAG_HASH  0x10

// FUNCTIONS

extern void _div_(div_t *d,int numer,int denom);
extern void _div__callee(div_t *d,int numer,int denom) __z88dk_callee;
#define _div_(a,b,c) _div__callee(a,b,c)


extern void _divu_(divu_t *d,unsigned int numer,unsigned int denom);
extern void _divu__callee(divu_t *d,unsigned int numer,unsigned int denom) __z88dk_callee;
#define _divu_(a,b,c) _divu__callee(a,b,c)


extern void _ldiv_(ldiv_t *ld,long numer,long denom);
extern void _ldiv__callee(ldiv_t *ld,long numer,long denom) __z88dk_callee;
#define _ldiv_(a,b,c) _ldiv__callee(a,b,c)


extern void _ldivu_(ldivu_t *ld,unsigned long numer,unsigned long denom);
extern void _ldivu__callee(ldivu_t *ld,unsigned long numer,unsigned long denom) __z88dk_callee;
#define _ldivu_(a,b,c) _ldivu__callee(a,b,c)


extern void _insertion_sort_(void *base,size_t nmemb,size_t size,void *compar);
extern void _insertion_sort__callee(void *base,size_t nmemb,size_t size,void *compar) __z88dk_callee;
#define _insertion_sort_(a,b,c,d) _insertion_sort__callee(a,b,c,d)


extern void _quicksort_(void *base,size_t nmemb,size_t size,void *compar);
extern void _quicksort__callee(void *base,size_t nmemb,size_t size,void *compar) __z88dk_callee;
#define _quicksort_(a,b,c,d) _quicksort__callee(a,b,c,d)


extern void _shellsort_(void *base,size_t nmemb,size_t size,void *compar);
extern void _shellsort__callee(void *base,size_t nmemb,size_t size,void *compar) __z88dk_callee;
#define _shellsort_(a,b,c,d) _shellsort__callee(a,b,c,d)


extern uint16_t _random_uniform_cmwc_8_(void *seed);
extern uint16_t _random_uniform_cmwc_8__fastcall(void *seed) __z88dk_fastcall;
#define _random_uniform_cmwc_8_(a) _random_uniform_cmwc_8__fastcall(a)


extern uint32_t _random_uniform_xor_32_(uint32_t *seed);
extern uint32_t _random_uniform_xor_32__fastcall(uint32_t *seed) __z88dk_fastcall;
#define _random_uniform_xor_32_(a) _random_uniform_xor_32__fastcall(a)


extern uint16_t _random_uniform_xor_8_(uint32_t *seed);
extern uint16_t _random_uniform_xor_8__fastcall(uint32_t *seed) __z88dk_fastcall;
#define _random_uniform_xor_8_(a) _random_uniform_xor_8__fastcall(a)


extern int _strtoi_(char *nptr,char **endptr,int base);
extern int _strtoi__callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define _strtoi_(a,b,c) _strtoi__callee(a,b,c)


extern uint16_t _strtou_(char *nptr,char **endptr,int base);
extern uint16_t _strtou__callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define _strtou_(a,b,c) _strtou__callee(a,b,c)


extern void abort(void) __preserves_regs(a,b,c,d,e,h,l);

extern int abs(int j) __preserves_regs(b,c,d,e);
extern int abs_fastcall(int j) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define abs(a) abs_fastcall(a)


extern int at_quick_exit(void *func);
extern int at_quick_exit_fastcall(void *func) __z88dk_fastcall;
#define at_quick_exit(a) at_quick_exit_fastcall(a)


extern int atexit(void *func);
extern int atexit_fastcall(void *func) __z88dk_fastcall;
#define atexit(a) atexit_fastcall(a)


extern double_t atof(char *nptr);
extern double_t atof_fastcall(char *nptr) __z88dk_fastcall;
#define atof(a) atof_fastcall(a)


extern int atoi(char *buf);
extern int atoi_fastcall(char *buf) __z88dk_fastcall;
#define atoi(a) atoi_fastcall(a)


extern long atol(char *buf);
extern long atol_fastcall(char *buf) __z88dk_fastcall;
#define atol(a) atol_fastcall(a)


extern void bsearch(void *key,void *base,size_t nmemb,size_t size,void *compar);
extern void bsearch_callee(void *key,void *base,size_t nmemb,size_t size,void *compar) __z88dk_callee;
#define bsearch(a,b,c,d,e) bsearch_callee(a,b,c,d,e)


extern size_t dtoa(double_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t dtoa_callee(double_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define dtoa(a,b,c,d) dtoa_callee(a,b,c,d)


extern size_t dtoe(double_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t dtoe_callee(double_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define dtoe(a,b,c,d) dtoe_callee(a,b,c,d)


extern size_t dtog(double_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t dtog_callee(double_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define dtog(a,b,c,d) dtog_callee(a,b,c,d)


extern size_t dtoh(double_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t dtoh_callee(double_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define dtoh(a,b,c,d) dtoh_callee(a,b,c,d)


extern void exit(int status) __preserves_regs(a,b,c,d,e,h,l);
extern void exit_fastcall(int status) __preserves_regs(a,b,c,d,e,h,l) __z88dk_fastcall;
#define exit(a) exit_fastcall(a)


extern size_t ftoa(float_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t ftoa_callee(float_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define ftoa(a,b,c,d) ftoa_callee(a,b,c,d)


extern size_t ftoe(float_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t ftoe_callee(float_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define ftoe(a,b,c,d) ftoe_callee(a,b,c,d)


extern size_t ftog(float_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t ftog_callee(float_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define ftog(a,b,c,d) ftog_callee(a,b,c,d)


extern size_t ftoh(float_t x,void *buf,uint16_t prec,uint16_t flags);
extern size_t ftoh_callee(float_t x,void *buf,uint16_t prec,uint16_t flags) __z88dk_callee;
#define ftoh(a,b,c,d) ftoh_callee(a,b,c,d)


extern char *itoa(int num,char *buf,int radix);
extern char *itoa_callee(int num,char *buf,int radix) __z88dk_callee;
#define itoa(a,b,c) itoa_callee(a,b,c)


extern long labs(long j) __preserves_regs(b,c);
extern long labs_fastcall(long j) __preserves_regs(b,c) __z88dk_fastcall;
#define labs(a) labs_fastcall(a)


extern char *ltoa(long num,char *buf,int radix);
extern char *ltoa_callee(long num,char *buf,int radix) __z88dk_callee;
#define ltoa(a,b,c) ltoa_callee(a,b,c)


extern void qsort(void *base,size_t nmemb,size_t size,void *compar);
extern void qsort_callee(void *base,size_t nmemb,size_t size,void *compar) __z88dk_callee;
#define qsort(a,b,c,d) qsort_callee(a,b,c,d)


extern void quick_exit(int status) __preserves_regs(a,b,c,d,e,h,l);
extern void quick_exit_fastcall(int status) __preserves_regs(a,b,c,d,e,h,l) __z88dk_fastcall;
#define quick_exit(a) quick_exit_fastcall(a)


extern int rand(void);

extern void srand(uint16_t seed) __preserves_regs(b,c,d,e);
extern void srand_fastcall(uint16_t seed) __preserves_regs(b,c,d,e,h,l) __z88dk_fastcall;
#define srand(a) srand_fastcall(a)


extern double_t strtod(char *nptr,char **endptr);
extern double_t strtod_callee(char *nptr,char **endptr) __z88dk_callee;
#define strtod(a,b) strtod_callee(a,b)


extern float_t strtof(char *nptr,char **endptr);
extern float_t strtof_callee(char *nptr,char **endptr) __z88dk_callee;
#define strtof(a,b) strtof_callee(a,b)


extern long strtol(char *nptr,char **endptr,int base);
extern long strtol_callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define strtol(a,b,c) strtol_callee(a,b,c)


extern uint32_t strtoul(char *nptr,char **endptr,int base);
extern uint32_t strtoul_callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define strtoul(a,b,c) strtoul_callee(a,b,c)


extern int system(char *s);
extern int system_fastcall(char *s) __z88dk_fastcall;
#define system(a) system_fastcall(a)


extern char *ultoa(uint32_t num,char *buf,int radix);
extern char *ultoa_callee(uint32_t num,char *buf,int radix) __z88dk_callee;
#define ultoa(a,b,c) ultoa_callee(a,b,c)


extern char *utoa(uint16_t num,char *buf,int radix);
extern char *utoa_callee(uint16_t num,char *buf,int radix) __z88dk_callee;
#define utoa(a,b,c) utoa_callee(a,b,c)



#ifndef _ALLOC_MALLOC_H

extern void *aligned_alloc(size_t alignment,size_t size);
extern void *aligned_alloc_callee(size_t alignment,size_t size) __z88dk_callee;
#define aligned_alloc(a,b) aligned_alloc_callee(a,b)


extern void *calloc(size_t nmemb,size_t size);
extern void *calloc_callee(size_t nmemb,size_t size) __z88dk_callee;
#define calloc(a,b) calloc_callee(a,b)


extern void free(void *p) __preserves_regs(b,c);
extern void free_fastcall(void *p) __preserves_regs(b,c) __z88dk_fastcall;
#define free(a) free_fastcall(a)


extern void *malloc(size_t size);
extern void *malloc_fastcall(size_t size) __z88dk_fastcall;
#define malloc(a) malloc_fastcall(a)


extern void *realloc(void *p,size_t size);
extern void *realloc_callee(void *p,size_t size) __z88dk_callee;
#define realloc(a,b) realloc_callee(a,b)



extern void *aligned_alloc_unlocked(size_t alignment,size_t size);
extern void *aligned_alloc_unlocked_callee(size_t alignment,size_t size) __z88dk_callee;
#define aligned_alloc_unlocked(a,b) aligned_alloc_unlocked_callee(a,b)


extern void *calloc_unlocked(size_t nmemb,size_t size);
extern void *calloc_unlocked_callee(size_t nmemb,size_t size) __z88dk_callee;
#define calloc_unlocked(a,b) calloc_unlocked_callee(a,b)


extern void free_unlocked(void *p) __preserves_regs(b,c);
extern void free_unlocked_fastcall(void *p) __preserves_regs(b,c) __z88dk_fastcall;
#define free_unlocked(a) free_unlocked_fastcall(a)


extern void *malloc_unlocked(size_t size);
extern void *malloc_unlocked_fastcall(size_t size) __z88dk_fastcall;
#define malloc_unlocked(a) malloc_unlocked_fastcall(a)


extern void *realloc_unlocked(void *p,size_t size);
extern void *realloc_unlocked_callee(void *p,size_t size) __z88dk_callee;
#define realloc_unlocked(a,b) realloc_unlocked_callee(a,b)



#endif

#ifdef __CLANG

extern long long atoll(char *buf);
extern void _lldiv_(lldiv_t *ld,long long numer,long long denom);
extern void _lldivu_(lldivu_t *ld,unsigned long long numer,unsigned long long denom);
extern long long llabs(long long i);
extern char *lltoa(long long num,char *buf,int radix);
extern long long strtoll(char *nptr,char **endptr,int base);
extern unsigned long long strtoull(char *nptr,char **endptr,int base);
extern char *ulltoa(unsigned long long num,char *buf,int radix);

#endif

#ifdef __SDCC

extern long long atoll(char *buf);
extern long long atoll_callee(char *buf) __z88dk_callee;
#define atoll(a) atoll_callee(a)

extern void _lldiv_(lldiv_t *ld,long long numer,long long denom);
extern void _lldiv__callee(lldiv_t *ld,long long numer,long long denom) __z88dk_callee;
#define _lldiv_(a,b,c) _lldiv__callee(a,b,c)


extern void _lldivu_(lldivu_t *ld,unsigned long long numer,unsigned long long denom);
extern void _lldivu__callee(lldivu_t *ld,unsigned long long numer,unsigned long long denom) __z88dk_callee;
#define _lldivu_(a,b,c) _lldivu__callee(a,b,c)



extern long long llabs(long long i);
extern long long llabs_callee(long long i) __z88dk_callee;
#define llabs(a) llabs_callee(a)
   
extern char *lltoa(long long num,char *buf,int radix);
extern char *lltoa_callee(long long num,char *buf,int radix) __z88dk_callee;
#define lltoa(a,b,c) lltoa_callee(a,b,c)


extern long long strtoll(char *nptr,char **endptr,int base);
extern long long strtoll_callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define strtoll(a,b,c) strtoll_callee(a,b,c)


extern unsigned long long strtoull(char *nptr,char **endptr,int base);
extern unsigned long long strtoull_callee(char *nptr,char **endptr,int base) __z88dk_callee;
#define strtoull(a,b,c) strtoull_callee(a,b,c)


extern char *ulltoa(unsigned long long num,char *buf,int radix);
extern char *ulltoa_callee(unsigned long long num,char *buf,int radix) __z88dk_callee;
#define ulltoa(a,b,c) ulltoa_callee(a,b,c)



#endif

#endif
