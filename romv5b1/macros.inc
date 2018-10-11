;======= Macros to provide "subroutines" without a stack =======

XCall	 MACRO	 link,tgt
	  LOCAL  Next
	LD	link,Next
	JP	tgt
Next	  EQU  $
	 ENDM


XRetn	 MACRO	 link
	JP	(link)
	 ENDM

;======== Macros to build Initialization Table Entries =========

Config	 MACRO   ?port, ?data
	DB	CFCNTL, ?port
	DB	CFDATA, ?data
	 ENDM

;------------------- End Macro Definitions --------------------
