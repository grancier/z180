; ----------------------------------------------------------------
; Z88DK INTERFACE LIBRARY FOR THE BIFROST*2 ENGINE
;
; See "bifrost2.h" for further details
; ----------------------------------------------------------------

; INCLUDED IN C INTERFACE DO NOT ADD TO LIST FILE

SECTION code_clib
SECTION code_bifrost2

PUBLIC asm_BIFROST2_setTile

EXTERN _BIFROST2_tilemap

asm_BIFROST2_setTile:

; L=px
; C=py
; E=tile
        ld a,l          ; A=px
        add a,a         ; A=px*2
        add a,a         ; A=px*4
        add a,l         ; A=px*5
        add a,a         ; A=px*10
        add a,c         ; A=px*10+py
        inc a           ; instead of: add a,_BIFROST2_tilemap%256
        ld l,a
        ld h,_BIFROST2_tilemap/256
        ld (hl),e
        ret
