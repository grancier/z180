
; void *balloc_addmem(unsigned char q, size_t num, size_t size, void *addr)

SECTION code_clib
SECTION code_alloc_balloc

PUBLIC _balloc_addmem

EXTERN l0_balloc_addmem_callee

_balloc_addmem:

   pop af
   exx
   pop bc
   exx
   pop bc
   pop hl
   pop de
   
   push de
   push hl
   push bc
   push bc
   push af
   
   jp l0_balloc_addmem_callee
