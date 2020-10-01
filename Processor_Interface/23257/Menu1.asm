init macro 
                MOV ax,@data
                MOV ds,ax							 
endm

prints macro
 								MOV ah,09h
 								INT 21h
endm

acceptch macro 
								MOV ah,01h
 				        INT 21h
endm

terminate macro
								MOV ah,04ch
                INT 21h
endm


.model small
.stack 100h
.data

                str1    db 25 DUP ('$')
                rev     db 25 DUP ('$')
                msg1    db 'Enter String: $'
                msg2    db 'Length      : $'
                msg3    db 'Reverse     : $' 
                msg4    db 13,10,'Palindrome String$'
                msg5		db 13,10,'Not Palindrome String$'
                flag    db 0

.code
					 MAIN PROC
                init
 
 								LEA si,str1
 								LEA di,rev
 								
 								LEA dx,msg1
 								prints
 								
 								CALL ACCEPT

								LEA dx,msg2
 								prints
 								
 								CALL REVERSE
 								
 								LEA dx,rev
 								prints 
 								
 								CALL PALINDROME
 								
 								terminate
 								
 								ret
 				     ENDP
 								
 				 ACCEPT PROC		
 								
 								MOV dl,[si]
 				 label1:acceptch
 						 		MOV [si],al
 						 		INC flag
 						 		INC si
 						 		CMP al,13
 						 		JNE label1
								
                ret
             ENDP
           
        REVERSE PROC
								
								MOV cl,flag
                SUB si,2
         
         label2:MOV al,[si]
						 		MOV [di],al
						 		INC di
						 		DEC si
						 		DEC cl
						 		CMP cl,0
						 		JNE label2 						 		
 						 		
 						 		ret
					   ENDP	 		
 					 
 		 PALINDROME PROC
 					 	 		
 						 		LEA si,str1
 						 		LEA di,rev
 						 		MOV cl,flag
 						 		SUB cl,1
                
 				 label3:MOV al,[si]
						 		MOV bl,[di]
						 	  CMP al,bl
						 	 	JNE label5
						 		INC si
						 		INC di
								DEC cl
								CMP cl,0
								JNE label3
														 		  
                LEA dx,msg3
						 		prints 
                
                ret
                
 				 label5:LEA dx,msg4
						 		prints
						 		
						 		ret
					   ENDP
end

