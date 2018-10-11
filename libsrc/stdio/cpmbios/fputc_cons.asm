;
;	Console routines
;	Created for Robotron KC85 but kept generic
;	By Stefano Bodrato - Sept. 2016
;
;	$Id: fputc_cons.asm,v 1.1 2016/09/22 06:29:49 stefano Exp $
;

	SECTION	code_clib
	PUBLIC	fputc_cons_native

.fputc_cons_native
	ld	hl,2
	add	hl,sp
	ld	a,(hl)
	
	ld  c,a
	cp  13
	jr  nz,nocr
	call $f00c		; conout
	ld  c,10
.nocr
	jp  $f00c		; conout
