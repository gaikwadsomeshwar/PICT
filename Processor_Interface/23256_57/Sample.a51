ORG 0000h
LJMP START

START:
		
		MOV R1,#04h
		MOV R2,#02h

		CLR A

		ADD A,R1
		ADD A,R2

   HERE:SJMP HERE

END
		