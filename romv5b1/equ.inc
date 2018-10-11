;::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
;		   C O M M O N    E Q U A T E S
; Combined from files by: D-X Designs Pty. Ltd.  4/12/95  D. R. Brooks
;::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

BELL	EQU	07H		; ASCII Characters
CR	EQU	0DH
LF	EQU	0AH
ascibs	EQU	08H
asciht	EQU	09H
ESC	EQU	1BH
space	EQU	' '
ascdel	EQU	7FH

;  Z80182  Port A Bit Definitions

RTCDat  EQU     0               ; DS-1202/1302 Data IO Bit
RTCClk  EQU     1               ; DS-1202/1302 Clock Bit
RTCRst  EQU     2               ; DS-1202/1302 Reset\ Bit
PaDSR	EQU	6		; PA-6 DSR input bit
PaRTS	EQU	7		; PA-7 RTS output bit

;============ Standard Microsystems FDC37C665/6 Configuration ===========

CFCNTL	EQU	90H		; Configuration control port
CFDATA	EQU	91H		; Configuration data port

;  Configuration Registers: see SMC data-sheet for details

CR0	EQU	0		; Power-save controls
CR1	EQU	1		; Serial/parallel port addresses
CR2	EQU	2		; UART setups
CR3	EQU	3		; FDC setups
CR4	EQU	4		; Parallel port setups
CR5	EQU	5		; FDC/IDE setups
		;Bit 7 6 5 4 3 2 1 0
		;    | | | | | +-+-+-  ?
		;    | | | +-+------- 00 = Density Normal (tracks Data Rate)
		;    | | |	      01 = (resvd), 10 = Force 1, 11 = Force 0
		;    +-+-+-----------  ?
CR6	EQU	6		; Floppy drive types
CR7	EQU	7		; Boot floppy drive, Media ID polarity
CR8	EQU	8		; ADRx lower address bits
CR9	EQU	9		; ADRx upper address bits
CRA	EQU	0AH		; ECP FIFO threshold
CRB	EQU	0BH		; Reserved
CRC	EQU	0CH		; Reserved
CRD	EQU	0DH		; Part sub-type: "65" or "66"
CRE	EQU	0EH		; Chip revision: "GT"=02, "IR"=82
CRF	EQU	0FH		; Reads as zero

; Port definitions for the Standard Microsystems FDC37C665/6 combo chips
;   Prefix a "_" as some names clash with Z180 names

;	FDC37C665/6 Diskette controller (82077-compatible)
_DOR	EQU	92H		; Digital Output
_MSR	EQU	94H		; Main Status
_DSR	EQU	94H		; Data-rate Select
_DATA	EQU	95H		; Data & commands I/O
_DIR	EQU	97H		; Digital Input
_CCR	EQU	97H		; Confign. Control

_DMA	EQU	0A0H		; Diskette DMA address

;  FDC37C665/6 Serial Port (16550-compatible)
;			RD/WR
_RBR	EQU	98H	;R	Receiver buffer
_THR	EQU	98H	;W	Transmit holding reg.
_IER	EQU	99H	;RW	Interrupt-enable reg.
_IIR	EQU	9AH	;R	Interrupt ident. reg.
_FCR	EQU	9AH	;W	FIFO control reg.
_LCR	EQU	9BH	;RW	Line control reg.
_MCR	EQU	9CH	;RW	Modem control reg.
_LSR	EQU	9DH	;RW	Line status reg.
_MMSR	EQU	9EH	;RW	Modem status reg. (name clash w. FDC)
_SCR	EQU	9FH	;N/A	Scratch reg. (not avail. in XT)
_DDL	EQU	98H	;RW	Divisor LSB | with DLAB
_DLM	EQU	99H	;RW	Divisor MSB | set high

;========================================================================
; Standard drive-parameter block.  Format is same as MS-DOS BIOS (mod-HFB)

SPEC_1	EQU	0		; "Specify" byte 1
SPEC_2	EQU	1		; "Specify" byte 2
MTROFF	EQU	2		; Wait before stop motor
SECSZE	EQU	3		; Bytes/sector (must be > 0)
EOT	EQU	4		; Final sector no.
GPL	EQU	5		; Gap length
DTL	EQU	6		; Data transfer length
GAPFMT	EQU	7		; Gap-3 length: Format
DATFMT	EQU	8		; Data fill: Format
SETTLE	EQU	9		; Head-settle time (mS)
MTRON	EQU	10		; Motor-start (* 1/8 sec.)
MAXCYL	EQU	11		; Max. cylinder no.
DRATE	EQU	12		; Data rate
SCTR_1	EQU	13		;; First Physical Sector Number

;========================================================================
; Standard drive-type identifiers

NTYPES	EQU	5		; No. of defined types

D5_360	EQU	0		; 5", 360kB
D5_120	EQU	1		; 5", 1.2MB
D3_720	EQU	2		; 3", 720kB
D3_144	EQU	3		; 3", 1.44MB
D3_288	EQU	4		; 3", 2.88MB

;=======================================================================
;  Equates for the National DP8490/NCR 5380 Prototype SCSI controller

NCR	EQU	40H		; Base of NCR 5380

; 5380 Chip Registers

NCRDAT	EQU	NCR		; Current SCSI Data		(Read)
				; Output Data Register		(Write)
NCRCMD	EQU	NCR+1		; Initiator Command Register	(Read/Write)
NCRMOD	EQU	NCR+2		; Mode Register			(Read/Write)
NCRTGT	EQU	NCR+3		; Target Command Register	(Read/Write)
NCRBUS	EQU	NCR+4		; Current SCSI Bus Status	(Read)
NCRST	EQU	NCR+5		; Bus & Status Register		(Read)
				; Start DMA Send		(Write)
NCRINT	EQU	NCR+7		; Reset Parity/Interrupt	(Read)
				; Start DMA Initiator Receive	(Write)
DMAACK	EQU	NCR+8		; SCSI Dack IO Port		(Read/Write)

; Bit Assignments for NCR 5380 Ports as indicated

B_ARST	EQU	10000000B	; Assert *RST		(NCRCMD)
B_AACK	EQU	00010000B	; Assert *ACK		(NCRCMD)
B_ASEL	EQU	00000100B	; Assert *SEL		(NCRCMD)
B_ABUS	EQU	00000001B	; Assert *Data Bus	(NCRCMD)

B_BSY	EQU	01000000B	; *Busy			(NCRBUS)
B_REQ	EQU	00100000B	; *Request		(NCRBUS)
B_MSG	EQU	00010000B	; *Message		(NCRBUS)
B_CD	EQU	00001000B	; *Command/Data		(NCRBUS)
B_IO	EQU	00000100B	; *I/O			(NCRBUS)
B_SEL	EQU	00000010B	; *Select		(NCRBUS)

B_PHAS	EQU	00001000B	; Phase Match		(NCRST)
B_BBSY	EQU	00000100B	; Bus Busy		(NCRST)

B_MBSY	EQU	00000100B	; Monitor Busy Flag	(NCRMOD)
B_DMA	EQU	00000010B	; DMA Mode of transfer	(NCRMOD)

;=======================================================================
;  Equates for Tillmann Reh's GIDE IDE/ATA Interface (Jumper for 50H Base)

GIDE	EQU	50H		; Set base of 16 byte address range
IDEDOR	EQU	GIDE+6		; Digital Output Register
IDEDat	EQU	GIDE+8		; IDE Data Register (16-bit wide)
IDEErr	EQU	GIDE+9		; IDE Error Register
IDESCnt	EQU	GIDE+0AH	; IDE Sector Count Register
IDESNum	EQU	GIDE+0BH	; IDE Sector Number Register
IDECLo	EQU	GIDE+0CH	; IDE Cylinder Number (Low)
IDECHi	EQU	GIDE+0DH	; IDE Cylinter Number (High)
IDESDH	EQU	GIDE+0EH	; IDE S-Drive-Head Register
IDECmd	EQU	GIDE+0FH	; IDE Command/Status Register

CMDRD	EQU	20H		; Read Sector Command
CMDWR	EQU	30H		; Write Sector Command
CMDVER	EQU	40H		; Verify Sector(s) Command
CMDDIAG	EQU	90H		; Execute Diagnostics Command
CMDINIT	EQU	91H		; Initialize Drive Params Command
CMDPW0	EQU	0E0H		; Low Range of Power Control Commands
CMDPW3	EQU	0E3H		; High Range of Power Control Commands
CMDPWQ	EQU	0E5H		; Power Status Query Command
CMDID	EQU	0ECH		; Read Drive Ident Data Command
