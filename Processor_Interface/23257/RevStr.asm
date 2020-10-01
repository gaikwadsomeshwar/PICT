.model small
.stack 100h
.data

                str1    db 25 DUP ('$')
                rev     db 25 DUP ('$')
                msg1    db 'Enter String: $'
                msg2    db 'Reverse     : $'
                flag    db 0

.code

                MOV ax,@data
                MOV ds,ax
 
 								LEA si,str1
 								
 								LEA dx,msg1
 								MOV ah,09h
 								INT 21h
 
 								MOV dl,[si]
 								MOV ah,01h
 						
 						 l1:INT 21h
 						 		MOV [si],al
 						 		INC flag
 						 		INC si
 						 		CMP al,13
 						 		JNE l1
                
                LEA dx,msg2
						 		MOV ah,09h
						 		INT 21h
							
								LEA di,rev
                SUB si,1
							
						 l2:MOV al,[si]
						 		MOV [di],al
						 		INC di
						 		DEC si
						 		DEC flag
						 		CMP flag,0
						 		JNE l2
						 		
						 		LEA dx,rev+1
						 		MOV ah,09h
						 		INT 21h		                   
                
                MOV ah,04ch
                INT 21h

end

