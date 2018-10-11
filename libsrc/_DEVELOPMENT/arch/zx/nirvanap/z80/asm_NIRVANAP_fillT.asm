; ----------------------------------------------------------------
; Z88DK INTERFACE LIBRARY FOR NIRVANA+ ENGINE - by Einar Saukas
;
; See "nirvana+.h" for further details
; ----------------------------------------------------------------

SECTION code_clib
SECTION code_nirvanap

PUBLIC asm_NIRVANAP_fillT

EXTERN asm_NIRVANAP_fillT_raw

asm_NIRVANAP_fillT:

   di
   call asm_NIRVANAP_fillT_raw
   ei
   ret
