ORG 0000h
LJMP START

START:
		
		CLR A
		
		MOV R2,#10
		MOV R1,#41h
   
   LOOP:ADD A,@R1 
   		INC R1
		DJNZ R2, LOOP
	
		MOV R6,A		

   HERE:SJMP HERE

END
		