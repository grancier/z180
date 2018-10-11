; ----------------------------------------------------------------
; Z88DK INTERFACE LIBRARY FOR NIRVANA+ ENGINE - by Einar Saukas
;
; See "nirvana+.h" for further details
; ----------------------------------------------------------------

SECTION code_clib
SECTION code_nirvanap

PUBLIC asm_NIRVANAP_drawW

EXTERN asm_NIRVANAP_drawW_raw

asm_NIRVANAP_drawW:

   di
   call asm_NIRVANAP_drawW_raw
   ei
   ret
