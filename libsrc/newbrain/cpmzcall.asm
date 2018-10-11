;
; Grundy Newbrain Specific libraries
;
; Stefano Bodrato - 19/05/2007
;
;
; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;
; This function is linked only in the CP/M extension version
; it calls the ROM functions via the CP/M facility
;
; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;
; Used internally only
;
; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;
;
; $Id: cpmzcall.asm,v 1.3 2016/06/19 20:33:40 dom Exp $
;

	SECTION code_clib
	PUBLIC ZCALL
	
.ZCALL
	jp	$f4fb	; CPMZCALL

