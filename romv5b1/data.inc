;=============   R O M    D A T A    A R E A   ==============
; Fixed Data Area uses FExx page in current RAM context.
; Equates used to ease problems with multiple assemblers.

IVPage	EQU	0FE00H		; Base Address of DSEG Page
				; 40H bytes reserved for Interrupts
;--- Data Used by Floppy Disk Driver ---

calibd	EQU	IVPage+40H	;-1 Drives "Calibrated" flags
mask	EQU	IVPage+41H	;-1 Bit-mask of Current Drive
restab	EQU	IVPage+42H	;-7 Buffer for Result-Phase Data
rtCnt	EQU	IVPage+49H	;-1 IO Command Retry Count (after restab)
switch	EQU	IVPage+4AH	;-3 Builds a JP instruction
blkSze	EQU	IVPage+4DH	;-2 Save Block Size

;--- Data Used by ROM Debugger ---

dbDat	EQU	IVPage+4FH	;-64 DEBUG Stack
Stack	EQU	IVPage+8FH	;-0
			;User-Environment Register-save area
SP_	EQU	Stack		;-2
PC_	EQU	Stack+2		;-2
IY_	EQU	Stack+4		;-2
IX_	EQU	Stack+6		;-2
HL?_	EQU	Stack+8		;-2
DE?_	EQU	Stack+10	;-2
BC?_	EQU	Stack+12	;-2
AF?_	EQU	Stack+14	;-2
HL_	EQU	Stack+16	;-2
DE_	EQU	Stack+18	;-2
BC_	EQU	Stack+20	;-2
AF_	EQU	Stack+22	;-2
regend	EQU	AF_+1		;-0 Final byte of saved regs.

spVa	EQU	IVPage+0A7H	;-2 Saved debug-level SP
bpAdr	EQU	spVa+2		;-2 Breakpoint address
inst	EQU	spVa+4		;-1 Instr. replaced by breakpoint
bpCnt	EQU	spVa+5		;-1 Count breaks before trapping
nxCnt	EQU	spVa+6		;-1 Count NEXT operations before halting
eiAdr	EQU	spVa+7		;-2 Addr. of extra EI Instr.
eiOpc	EQU	spVa+9		;-1 Opcode replaced by EI instr.
inPtr	EQU	spVa+10		;-2 Input-buffer ptr.
hexLin	EQU	spVa+12		;-2 Line-count of hex. input file
errLin	EQU	spVa+14		;-2 Line-number of last error seen (or 0)
			; Input-queue controls
QSBIT	EQU	6		; Queue-size mask bit
QIPTR	EQU	0		; Offset of Input Ptr.
QOPtr	EQU	1		; Offset of Output Ptr.
QBUFF	EQU	2		; Offset of Buffer
qSpace	EQU	spVa+16		;-66(42H) Queue Space

conBuf	EQU	qSpace+42H	;-81 Standard Console I/O Buffer
SZBUF	EQU	81

;   -- Upper buffer space used for Config space --
timAry	EQU	conBuf+49	; (8 byte Date/Time from DS-1202/1302 RAM)
ramAry	EQU	conBuf+57	; (24 bytes from DS-1202/1302 RAM)

sysFlg	EQU	conBuf+81	;-1 DEBUG Status Flag
			; Bits in sysFlg
ATBRK	EQU	0		; RST-38 was the set breakpoint
			; Intel Hex-Format Errors
IFHEX	EQU	5		; Bad Hex. Digit
IFADR	EQU	6		; Address Out-of-Range
IFSUM	EQU	7		; Bad SumCheck

MONTOP	EQU	sysFlg+1	; End of Monitor's RAM

;============== Non-Volatile Clock RAM Storage ==============

NVRate	EQU	MONTOP		;-1 FF = N-V RAM Checksum Bad, Else Con: Rate
nvRam0	EQU	MONTOP+1	;-1 Speed & wait settings
nvRam1	EQU	MONTOP+2	;-1 Floppy 0 Physical Params
nvRam2	EQU	MONTOP+3	;-1 Floppy 0 Timings
nvRam5	EQU	MONTOP+4	;-1 Hard Drive Type Byte
nvRam10	EQU	MONTOP+5	;-1 Hardware mode bits
nvRamx	EQU	MONTOP+6	;-1 undefined for future expansion

;============== SCSI Data Storage requirements ==============

HDCMDV	EQU	MONTOP+7	;-2 Storage for Current Command Data Block
HDDATV	EQU	MONTOP+9	;-2 Storage for current Data Transfer Area
SNSDAT	EQU	MONTOP+11	;-4 Storage for Sense Data Transferred
HDBUFR	EQU	MONTOP+15	;-2 Storage for Load Point Address

; SCSI Controller Command Block

HDCOMD	EQU	MONTOP+17	;-1 Command Byte
HDUNIT	EQU	MONTOP+18	;-1 B7-5 = Unit #, remainder is Hi-Addr
HIBLK	EQU	MONTOP+19	;-1 Mid-Addr Byte
LOBLK	EQU	MONTOP+20	;-1 Lo-Addr Byte
HDSIZ	EQU	MONTOP+21	;-2 Block Size to Read/Write (1=512 byte blk)

DATPTR	EQU	MONTOP+23	;-2 Pointer to Data Area
DATADR	EQU	MONTOP+25	;-2 Pointer to User Buffer Space (user bank)

;<<--- WARNING! --- Do not re-order the following Two Bytes --->>

STATUS	EQU	MONTOP+27	;-1 Ending Status Byte
MESSAGE	EQU	MONTOP+28	;-1 Ending Message Byte

SCSIOk	EQU	MONTOP+29	;-1 0 = Controller present, Non-0 = No SCSI
HDONE	EQU	MONTOP+30	;-1 0 = SCSI Working, FF = Done

;;============== GIDE Data Storage requirements ==============
; This driver re-uses some of the SCSI Data locations since only one is active

hdTrks	EQU	MONTOP+11	;-2 Number of Tracks on (Logical) Drive
hdHds	EQU	MONTOP+13	;-1 Number of Heads on (Logical) Drive
hdSPT	EQU	MONTOP+14	;-1 Number of Sectors-Per-Track (Logical)

; IDE/ATA Task File Register Command Block for GIDE

;hdComd	EQU	MONTOP+17	;-1 Drive Command
hdBMap	EQU	MONTOP+18	;-1 Bit Map of Registers to Set
hdHead	EQU	MONTOP+19	;-1 Drive/Head Byte
hdTrkH	EQU	MONTOP+20	;-1 High Byte of Track #
hdTrkL	EQU	MONTOP+21	;-1   Low Byte of Track #
hdSec	EQU	MONTOP+22	;-1 Sector #
hdSCnt	EQU	MONTOP+23	;-1 Sector Count
hdErr	EQU	MONTOP+24	;-1 Error Status/Mode Register
hdDig0	EQU	MONTOP+25	;-1 Digital Output Register

hRTrys	EQU	MONTOP+26	;-1 Retry Count Register
GIDEOk	EQU	MONTOP+31	;-1 0 = GIDE Present, Non-0 = No GIDE

; Misc OS flags

OsEx	EQU	MONTOP+32	;-1 Return from OS load flag
				;   0 = No return (Execute after Load)
				;   1 = Return (No Execute after Load)
OsAdd	EQU	MONTOP+33	;-2 OS Execution address

;==================  E N D    D A T A    A R E A  ===================
