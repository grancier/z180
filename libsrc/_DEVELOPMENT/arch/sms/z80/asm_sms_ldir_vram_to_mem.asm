; ========================================================================
; 
; void *sms_ldir_vram_to_mem(void *dst, void *src, unsigned int n)
;
; ldir from vram to memory; VRAM addresses are assumed to be stable.
;
; ========================================================================

SECTION code_clib
SECTION code_crt_common

PUBLIC asm_sms_ldir_vram_to_mem
PUBLIC asm_sms_ldir_vram_to_mem_continue

EXTERN asm_sms_set_vram_read_hl

asm_sms_ldir_vram_to_mem:

   ; memcpy from vram to memory
   ;
   ; enter : hl = void *src in vram
   ;         de = void *dst in memory
   ;         bc = unsigned int n > 0
   ;
   ; exit  : hl = void *src, &byte after last read
   ;         de = void *dst, &byte after last written
   ;
   ; uses  : af, bc, de, hl

   call asm_sms_set_vram_read_hl

   add hl,bc
   ex de,hl

asm_sms_ldir_vram_to_mem_continue:

   ; hl = void *dst in memory
   ; bc = unsigned int n > 0
   ; VRAM has src address set

   ld a,b
   inc a
   ld b,c
   
   inc b
   djnz no_adjust
   dec a
   
no_adjust:
   
   ld c,$be
   
loop:

   ini
   
   inc b
   djnz loop
   
   dec a
   jp nz, loop
   
   ex de,hl
   ret
 