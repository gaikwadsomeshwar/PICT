ORG 0000h

INIT: MOV A, 35h     ;Use 2 lines of the matrix
      ACALL CMND

      MOV A, #0Fh    ;LCD On
      ACALL CMND

      MOV A, #01h    ;Clear Screen
      ACALL CMND

      MOV A, #80h   ;Select the 1st line
      ACALL CMND

MOV A, #'P'
ACALL DISP

MOV A, #'I'
ACALL DISP

MOV A, #'C'
ACALL DISP

MOV A, #'T'
ACALL DISP

CMND: MOV P1, A  ; Read from P1 port
      CLR P2.0   ; Clear RS for selecting Command Register
      CLR P2.1   ; Clear R/W for Read Operation
      SETB P2.2
      CLR P2.2   ; High to Low Pulse for Enable
      ACALL DELAY
    RET

DISP: MOV P1, A  ; Read from P1 port
      SETB P2.0   ; Set RS for selecting Data Register
      CLR P2.1   ; Clear R/W for Read Operation
      SETB P2.2
      CLR P2.2   ; High to Low Pulse for Enable
      ACALL DELAY
    RET

DELAY: MOV R3, #0FFh
LOOP1: MOV R2, #0FF
LOOP2: DJNZ R2, LOOP2

       DJNZ R1, LOOP1
      RET
END
