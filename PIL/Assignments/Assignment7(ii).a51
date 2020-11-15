ORG 0000h
LJMP START

START:
		
		CLR A
		
		MOV R0,#31h
		MOV R1,#31h
		MOV R2,#5

   LOOP:MOV A,@R1
   		MOVX @R1,A
		INC R1
		INC R0
		DJNZ R2,LOOP 		

   HERE:SJMP HERE

END