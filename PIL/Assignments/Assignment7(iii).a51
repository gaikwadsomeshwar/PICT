ORG 0000h
LJMP START

START:
		
		CLR A
		
		MOV R0,#30h
		MOV R1,#49h
		MOV R2,#5

   LOOP:MOVX A,@R0
   		MOVX @R1,A
		INC R1
		INC R0
		DJNZ R2,LOOP 		

   HERE:SJMP HERE

END