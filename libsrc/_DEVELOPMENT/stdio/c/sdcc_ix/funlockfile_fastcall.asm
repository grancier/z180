
; void funlockfile_fastcall(FILE *file)

SECTION code_clib
SECTION code_stdio

PUBLIC _funlockfile_fastcall

EXTERN asm_funlockfile

_funlockfile_fastcall:
   
   push hl
   ex (sp),ix

   call asm_funlockfile
   
   pop ix
   ret