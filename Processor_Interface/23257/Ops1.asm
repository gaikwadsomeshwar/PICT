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

printch macro   
								MOV ah,02h
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
                menu    db '1. Print Length',13,10,'2. Reverse String',13,10,'3. Check Palindrome',13,10,'4. Exit',13,10,'Your Choice : $'
                msg1    db 'Enter String: $'
                msg2    db 13,10,13,10,'Reverse     : $'
                msg3    db 13,10,13,10,'Length      : $'
                msg4    db 13,10,13,10,'It is a Palindrome String$'
                msg5		db 13,10,13,10,'It is Not a Palindrome String$'
                msg6    db 13,10,13,10,'Incorrect Choice$'
                newline db 13,10,13,10,'$'
                flag    db 0
								choice  db ?
								
.code
					 MAIN PROC
                init
 
 								LEA si,str1
 								LEA di,rev
 								
 								LEA dx,msg1
 								prints
 								
 								CALL ACCEPT
 								
 					loop1:LEA dx,menu
 								prints
 								
 								acceptch
 								MOV choice,al	
 								SUB choice,30h							

								CALL SWITCH
								JMP loop1
 								ret
 				     ENDP
 					
 				 SWITCH PROC					

					case1:CMP choice,1
								JNE case2
								CALL STRLEN
 								LEA dx,newline
 								prints								
								ret
								
					case2:CMP choice,2
 								JNE case3
 								CALL REVERSE
 								LEA dx,newline
 								prints 								
 								ret

					case3:CMP choice,3
 								JNE case4
 								CALL PALINDROME
 								LEA dx,newline
 								prints
 								ret
 					
 					case4:CMP choice,4
 								JNE default
 								terminate
 				
 				default:LEA dx,msg6
 								prints
 								LEA dx,newline
 								prints 								
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
             
         STRLEN PROC
								LEA dx,msg3
								prints
								MOV dl,flag
								SUB dl,1
								ADD dl,30h
								printch
								ret
						 ENDP		
								          
        REVERSE PROC
								
								LEA dx,msg2
 								prints								
								
								MOV cl,flag
                SUB si,2
         
         label2:MOV al,[si]
						 		MOV [di],al
						 		INC di
						 		DEC si
						 		DEC cl
						 		CMP cl,0
						 		JNE label2 						 		
 						 		
 								LEA dx,rev
 								prints  						 		 						 		
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
														 		  
                LEA dx,msg4
						 		prints 
                ret
                
 				 label5:LEA dx,msg5
						 		prints
						 		ret
					   ENDP
end

