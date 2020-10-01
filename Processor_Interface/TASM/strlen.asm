.model small
.stack 100h
.data

                str1    db 25 DUP ('$')
                msg1    db 'Enter String: $'
                msg2    db 'String: $'
                msg3    db 'Length: $'
                newline db 13,10
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
                
                LEA dx,msg3
                MOV ah,09h
                INT 21h
                
                SUB flag,1
                ADD flag,30h
                MOV dl,flag
                MOV ah,02h
                INT 21h
                
                MOV ah,04ch
                INT 21h

end

