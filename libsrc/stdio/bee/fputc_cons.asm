;
;	MicroBEE Stdio
;
;	(HL)=char to output to console
;
;	Stefano Bodrato - 2016
;
;
;	$Id: fputc_cons.asm,v 1.1 2016/11/15 08:11:11 stefano Exp $
;


	SECTION code_clib
	PUBLIC	fputc_cons_native

.fputc_cons_native
	ld	hl,2
	add	hl,sp
	ld	a,(hl)
	cp  12
	jr  nz,nocls
	ld  a,$1a
.nocls
	cp  13
	jr nz,nocr
	ld  b,13
	call $800C
	ld  a,10
.nocr
	ld  b,a
	jp	$800C
