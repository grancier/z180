

false	equ	0
true	equ	1
;========== Z180 Internal Interrupt Vectors ========

; The following vectors are offsets from the value 
; loaded in IL, the Interrupt Vector Low register.

VINT1	equ	0	;External INT-1 pin
VINT2	equ	2	;External INT-2 pin
VPRT0	equ	4	;Timer 0
VPRT1	equ	6	;Timer 1
VDMA0	equ	8	;DMA Ch-0
VDMA1	equ	0ah	;DMA Ch-1
VCSIO	equ	0ch	;Clocked serial I/O
VASC0	equ	0eh	;Asynch. comms. Ch-0
VASC1	equ	10h	;Asynch. comms. Ch-1

;========== Z180 System Control Registers ==========

;NB These registers may be relocated to multiples of
; 40H, by setting the IO Control Register (ICR = 3FH)
; The addresses below are valid with ICR=0 (else they
; are offsets from the ICR base value).

;ASCI Registers
cntla0  equ     00h     ;ASCI Control Reg A Ch0
cntla1  equ     01h     ;ASCI Control Reg A Ch1
cntlb0  equ     02h     ;ASCI Control Reg B Ch0
cntlb1  equ     03h     ;ASCI Control Reg B Ch1
stat0   equ     04h     ;ASCI Status Reg Ch0
stat1   equ     05h     ;ASCI Status Reg Ch1
tdr0    equ     06h     ;ASCI TX Data Reg Ch0
tdr1    equ     07h     ;ASCI TX Data Reg Ch1
rdr0    equ     08h     ;ASCI RX Data Reg Ch0
rdr1    equ     09h     ;ASCI RX Data Reg Ch1
brk0    equ     12h     ;Break Control Reg Ch0
brk1    equ     13h     ;Break Control reg Ch1

;CSI/O Registers
cntr    equ     0ah     ;CSI/O Control Reg
trdr    equ     0bh     ;CSI/O TX/RX Data Reg

ccr     equ     1fh     ;CPU control reg.
intype  equ     0dfh    ;Interrupt edge/pin mux reg.
wsgcs   equ     0d8h    ;Wait-State Generator CS
enh182  equ     0d9h    ;Z80182 Enhancements Reg
pinmux  equ     0dfh    ;Interrupt Edge/Pin Mux Reg
ramubr  equ     0e6h    ;RAM End Boundary
ramlbr  equ     0e7h    ;RAM Start Boundary
rombr   equ     0e8h    ;ROM Boundary

romend	equ		0e8h
ramstart	equ	0e7h
ramend		equ	0e6h

fifoctl equ     0e9h    ;FIFO Control Reg
rtotc   equ     0eah    ;RX Time-Out Time Const
ttotc   equ     0ebh    ;TX Time-Out Time Const
fcr     equ     0ech    ;FIFO Register
scr     equ     0efh    ;System Pin Control
rbr     equ     0f0h    ;MIMIC RX Buffer Reg
thr     equ     0f0h    ;MIMIC TX Holding Reg
ier     equ     0f1h    ;Interrupt Enable Reg
lcr     equ     0f3h    ;Line Control Reg
mcr     equ     0f4h    ;Modem Control Reg
lsr     equ     0f5h    ;Line Status Reg
msr     equ     0f6h    ;Modem Status Reg
mscr    equ     0f7h    ;MIMIC Scratch Reg
dlatl   equ     0f8h    ;Divisor latch LS
dlatm   equ     0f9h    ;Divisor latch MS
ttcr    equ     0fah    ;TX Time Constant
rtcr    equ     0fbh    ;RX Time Constant
ivec    equ     0fch    ;MIMIC Interrupt Vector
mimie   equ     0fdh    ;MIMIC Interrupt Enable Reg
iusip   equ     0feh    ;MIMIC Interrupt Under-Service Reg
mmcr    equ     0ffh    ;MIMIC Master Control Reg

;DMA Registers
sar0l   equ     20h     ;DMA Source Addr Reg Ch0-Low
sar0h   equ     21h     ;DMA Source Addr Reg Ch0-High
sar0b   equ     22h     ;DMA Source Addr Reg Ch0-B
dar0l   equ     23h     ;DMA Destn  Addr Reg Ch0-Low
dar0h   equ     24h     ;DMA Destn  Addr Reg Ch0-High
dar0b   equ     25h     ;DMA Destn  Addr Reg Ch0-B
bcr0l   equ     26h     ;DMA Byte Count Reg Ch0-Low
bcr0h   equ     27h     ;DMA Byte Count Reg Ch0-High
mar1l   equ     28h     ;DMA Memory Addr Reg Ch1-Low
mar1h   equ     29h     ;DMA Memory Addr Reg Ch1-High
mar1b   equ     2ah     ;DMA Memory Addr Reg Ch1-B
iar1l   equ     2bh     ;DMA I/O Addr Reg Ch1-Low
iar1h   equ     2ch     ;DMA I/O Addr Reg Ch1-High
bcr1l   equ     2eh     ;DMA Byte Count Reg Ch1-Low
bcr1h   equ     2fh     ;DMA Byte Count Reg Ch1-High
dstat   equ     30h     ;DMA Status Reg
dmode   equ     31h     ;DMA Mode Reg
dcntl   equ     32h     ;DMA/WAIT Control Reg


;System Control Registers
il      equ     33h     ;INT Vector Low Reg
itc     equ     34h     ;INT/TRAP Control Reg
rcr     equ     36h     ;Refresh Control Reg
cbr     equ     38h     ;MMU Common Base Reg
bbr     equ     39h     ;MMU Bank Base Reg
cbar    equ     3ah     ;MMU Common/Bank Area Reg
omcr    equ     3eh     ;Operation Mode Control Reg
icr     equ     3fh     ;I/O Control Reg

;--- Character Device Section ---


		; The following two devices result in non-standard data rates
		; with the standard 16.00 MHz crystal in the P112.  If a more
		; "standard" crystal is used (12.288, 18.432, 24.576 MHz etc)
		; is used, the ports become usable.
		;   Driver code for ASCI0 and ASCI1 includes an option for
		; assembling Polled or Interrupt-driven buffered input.
		; Select the desired option for ASCI0 with the BUFFA0 flag,
		; and BUFFA1 for ASCI1.
ASCI_0	EQU	false		; Include ASCI0 Driver?
BUFFA0	EQU	false		;   Use buffered ASCI0 Input Driver?
ASCI_1	EQU	false		; Include ASCI1 Driver?
BUFFA1	EQU	false		;   Use buffered ASCI1 Input Driver?

QSIZE	EQU	32		; size of interrupt typeahead buffers (if used)
				; ..must be 2^n with n<8
RTSCTS	EQU	false		; Include RTS/CTS code on Serial Outputs?
XONOFF  EQU false ; Include Xon/Xoff handshaking in Serial lines?


;******************************************************************
;INIT_UART
;Function: Initialize the UART to BAUD Rate 9600 (1.8432 MHz clock input)
;DLAB A2 A1 A0 Register
;0    0  0  0  Receiver Buffer (read),
;              Transmitter Holding
;              Register (write)
;0    0  0  1  Interrupt Enable
;X    0  1  0  Interrupt Identification (read)
;X    0  1  0  FIFO Control (write)
;X    0  1  1  Line Control
;X    1  0  0  MODEM Control
;X    1  0  1  Line Status
;X    1  1  0  MODEM Status
;X    1  1  1  Scratch
;1    0  0  0  Divisor Latch
;              (least significant byte)
;1    0  0  1  Divisor Latch
;              (most significant byte)
;******************************************************************
;***********************************
;*  UART Test Program              *
;*                                 *
;***********************************

.ORG 00000H

INIT_UART:
            LD     A,80H       ; Mask to Set DLAB Flag
			db      0edh
			OUT    (03H),A
			LD     A,12        ; Divisor = 12 @ 9600bps w/ 1.8432 Mhz
			OUT    (00H),A     ; Set BAUD rate to 9600
			LD     A,00
			OUT    (01H),A     ; Set BAUD rate to 9600
			LD     A,03H
			OUT    (03H),A     ; Set 8-bit data, 1 stop bit, reset DLAB Flag
			
;******************************************************************
;Main Program
;Function: Display A->Z then a new line and loop
;******************************************************************


MAIN_LOOP:   
			IN      A,(05H)        ; Get the line status register's contents
			BIT     5,A            ; Test BIT, it will be set if the UART is ready
			JP      Z,MAIN_LOOP    
			LD      A,41H          ; Load acumulator with "A" Character
			OUT     (00H),A        ; Send "A" Character through the UART
			JP      MAIN_LOOP

.END