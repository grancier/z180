;
;==================================================================================================
; TIME ROUTINES
;==================================================================================================
;
; COMPUTE DAY OF WEEK FROM YEAR, MONTH, DAY
;   INPUT: HL IS FULL YEAR VALUE,
;          D IS MONTH, E IS DATE
;   RESULT: A=0-6 (SUN-SAT)
;
; DD + MX + YY + (YY/4) + CX
; MX IS LOOKUP BASED ON ZERO INDEXED MONTH FOR
;   LEAP YEAR: 0,3,3,6,1,4,6,2,5,0,3,5
;   NON-LEAP YEAR: -1,2,3,6,1,4,6,2,5,0,3,5
; CX IS 6 IF CENTURY DIVISIBLE BY 4, THEN, 4, 2, 0
;   SO 20XX = 6, 19XX = 4, 18XX = 2, 17XX = 0, 16XX = 6, ETC.
;
DOW:
	; SAVE INCOMING MONTH AND DATE
	LD	(DOW_DT),DE	; SAVE DATE TO DT AND MONTH TO MO
	; DETERMINE CENTURY AND YEAR OF CENTURY FROM FULL YEAR
	PUSH	HL		; SAVE FULL YEAR VALUE
	LD	DE,100		; DIVIDE BY 100 TO GET CC/YY
	CALL	DIV16		; BC NOW HAS CENTURY, HL HAS YEAR OF CENTURY
	LD	A,L		; MOVE YEAR TO A, DISCARD H NOT NEEDED
	LD	(DOW_YR),A	; SAVE YY
	LD	A,C		; MOVE CENTURY TO A, DISCARD B NOT NEEDED
	LD	(DOW_CC),A	; SAVE CENTURY
	; USING FULL YEAR VALUE, CHECK FOR LEAP YEAR
	POP	HL		; GET FULL YEAR VALUE BACK
	CALL	LEAP		; CHECK FOR LEAP YEAR, Z IF SO
DOW1:
	; LOOKUP MX VALUE BASED MONTH USING APPROPRIATE TABLE
	LD	HL,DOW_MX1	; POINT TO MONTH VALUE TABLE
	JR	NZ,DOW2		; NOT LEAP, USE STD TBL
	LD	HL,DOW_MX2	; LEAP YEAR, USE LEAP TBL
DOW2:
	LD	A,(DOW_MO)	; GET MONTH
	DEC	A		; ZERO OFFSET
	CALL	ADDHLA		; LOOKUP SPECIAL MONTH VALUE
	LD	A,(HL)		; A NOW HAS SPECIAL MONTH VALUE
	LD	B,A		; SAVE IT IN B
;
	; B NOW HAS INITIAL WORKING VALUE, ADD IN DATE
	LD	A,(DOW_DT)	; GET DATE
	ADD	A,B		; ADD WITH SPECIAL MONTH VALUE
	LD	B,A		; SAVE IT
;
	; ADD IN YEAR OF CENTURY
	LD	A,(DOW_YR)	; GET TWO DIGIT YEAR VALUE
	ADD	A,B		; ADD WITH WORKING VALUE
	LD	B,A		; SAVE IT
;
	; ADD IN (YEAR OF CENTURY / 4)
	LD	A,(DOW_YR)	; GET TWO DIGIT YEAR AGAIN
	SRL	A		; DIVIDE BY 4
	SRL	A		; .. BY SHIFTING
	ADD	A,B		; ADD WITH WORKING VALUE
	LD	B,A		; SAVE IT
;
	; DETERMINE CX = 6 - ((CC % 4) * 2)
	LD	A,(DOW_CC)	; GET CC
	AND	3		; MOD 4
	SLA	A		; * 2
	NEG
	ADD	A,6
;
	; COMBINE CX WITH WORKING VALUE TO GET FINAL VALUE IN A
	ADD	A,B		; ADD WITH WORKING VALUE
	; CALC FINAL VALUE MOD 7 TO GET WEEKDAY VALUE 0-6
	LD	B,7		; SUB IN INCREMENTS OF 7
DOW3:
	SUB	B		; NEXT SUBTRACTION
	JR	NC,DOW3		; IF NO CARRY, KEEP GOING SUBTRACTING
	ADD	A,B		; WENT TOO FAR, ADD 7 BACK TO GET RESULT
	RET
;
DOW_MX1		.DB	0,3,3,6,1,4,6,2,5,0,3,5
DOW_MX2		.DB	-1,2,3,6,1,4,6,2,5,0,3,5
;
DOW_CC	.DB	0
DOW_YR	.DB	0
DOW_DT	.DB	0
DOW_MO	.DB	0
;
; DERIVE DOW FROM STARNDARD TIME BUFFER AT HL
;   RETURN DOW IN A (0-6: SUN-SAT)
;
TIMDOW:
	PUSH	HL
	INC	HL			; POINT TO MONTH
	LD	A,(HL)			; LOAD MONTH (BCD)
	CALL	BCD2BYTE		; CVT TO BINARY
	LD	D,A			; D := MONTH (BINARY)
	INC	HL			; POINT TO DATE
	LD	A,(HL)			; LOAD DATE (BCD)
	CALL	BCD2BYTE		; CVT TO BINARY
	LD	E,A			; E := DATE (BINARY)
	POP	HL			; RECOVER PTR TO START OF BUF
	PUSH	DE			; SAVE DE FOR NOW
	LD	A,(HL)			; LOAD YEAR OF CENTURY (BCD)
	CALL	BCD2BYTE		; CVT TO BINARY
	LD	L,A			; YEAR VALUE
	LD	H,0			; .. IN HL
	LD	DE,2000			; ASSUME CENTURY IS 20XX
	ADD	HL,DE			; .. AND ADD IT IN TO THE YEAR VALUE IN HL
	POP	DE			; RECOVER DE (MONTH, DATE)
	JP	DOW
;
; PRINT DATE AND TIME
;   INPUT: YYMMDDHHMMSS BUFFER AT HL (BCD ENCODED)
;
PRTDT:
	PUSH	HL			; SAVE BUFFER POINTER
	CALL	TIMDOW
	CALL	PRTDOW
	POP	HL			; RECOVER PTR TO START OF BUF
	CALL	PC_SPACE
	LD	A,'2'
	CALL	COUT
	LD	A,'0'
	CALL	COUT
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	LD	A,'-'
	CALL	COUT
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	LD	A,'-'
	CALL	COUT
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	CALL	PC_SPACE
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	CALL	PC_COLON
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	CALL	PC_COLON
	LD	A,(HL)
	INC	HL
	CALL	PRTHEXBYTE
	RET
;
; PRINT DAY OF WEEK BASED ON A
;   0-6 IS SUN-SAT
;
PRTDOW:
	; BOUNDS CHECK FIRST
	CP	7		; MAX VALUE + 1
	RET	NC		; ABORT IF OUT OF RANGE!
	LD	HL,DOWTBL
	SLA	A
	SLA	A
	CALL	ADDHLA
	JP	PRTSTR
;
DOWTBL		.DB	"Sun$", "Mon$", "Tue$", "Wed$"
		.DB	"Thu$", "Fri$", "Sat$"
;
; SET Z IF YEAR VALUE IN HL REPRESENTS A LEAP YEAR, ELSE NZ
; HL IS PRESERVED
;
LEAP:
	LD	DE,4
	CALL	LEAPDIV
	JR	NZ,NOLEAP	; IF YEAR NOT DIVISIBLE BY 4: NOT LEAP
	LD	DE,100
	CALL	LEAPDIV
	JR	NZ,ISLEAP	; ELSE IF YEAR NOT DIVISIBLE BY 100: LEAP
	LD	DE,400
	CALL	LEAPDIV
	JR	Z,ISLEAP	; ELSE IF YEAR DIVISIBLE BY 400: LEAP
	JR	NOLEAP		; OTHERWISE NOT LEAP
;
NOLEAP:
	OR	$FF		; NZ SIGNALS FALSE (NOT LEAP YEAR)
	RET
;
ISLEAP:
	XOR	A		; ZF SIGNALS TRUE (IS LEAP YEAR)
	RET
;
LEAPDIV:
	; SET Z FLAG BASED ON REMAINDER OF HL / DE
	; PRESERVE HL
	PUSH	HL
	CALL	DIV16
	;LD	A,H
	;OR	L
	POP	HL
	RET
