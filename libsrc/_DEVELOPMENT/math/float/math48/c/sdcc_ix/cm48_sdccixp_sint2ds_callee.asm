
; float __sint2fs_callee(signed int si)

SECTION code_clib
SECTION code_fp_math48

PUBLIC cm48_sdccixp_sint2ds_callee

EXTERN am48_double16, cm48_sdccixp_m482d

cm48_sdccixp_sint2ds_callee:

   ; signed int to double
   ;
   ; enter : stack = signed int si, ret
   ;
   ; exit  : dehl = sdcc_float(si)
   ;
   ; uses  : af, bc, de, hl, bc', de', hl'

   pop af
   pop hl
   push af

   call am48_double16
   
   jp cm48_sdccixp_m482d
