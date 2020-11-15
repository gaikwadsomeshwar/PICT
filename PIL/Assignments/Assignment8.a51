;---------------------------------------------------------------------------
;Assignment No.8
;Title:Serial port programming: ISR based 
;program for the 8051 to transfer ?PICT? serially at 9600baud, 8-bit data, 1 stop bit
;-------------------------------------------------------------------------------

	MOV TMOD,#20H 	;timer 1,mode 2(auto reload)
	MOV TH1,#-3 	;9600 baud rate
	MOV SCON,#50H 	;8-bit, 1 stop, REN enabled
	SETB TR1	;start timer 1
AGAIN: 	MOV A,#050h	;transfer ?P?
	ACALL TRANS
	MOV A,#049h	;transfer ?I?
	ACALL TRANS
	MOV A,#043h	;transfer ?C?
	ACALL TRANS
	MOV A,#054h	;transfer ?T?
	ACALL TRANS
	MOV A,#02Ah	;transfer ?*?
	ACALL TRANS
	SJMP AGAIN	;keep doing it

	;serial data transfer subroutine

TRANS: 	MOV SBUF,A	;load SBUF
HERE: 	JNB TI,HERE	;wait for the last bit
	CLR TI		;get ready for next byte
	RET

