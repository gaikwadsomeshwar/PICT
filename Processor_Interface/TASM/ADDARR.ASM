.model small
.stack 100h
.data
                arr  db 100 DUP(?)
                len  db ?
                res  db 0
              	Q    db 0
              	R    db 0
                D    db 0Ah
                endl db 13,10,'$'
                S2   db 13,10,'Enter Value: $',13,10
                S3   db 13,10,'Result: $',13,10
								S1   db 13,10,'Size: $',13,10	

.code

                MOV ax,@data
                MOV ds,ax

								MOV ah,09h      ;Message for accepting
                LEA dx,S1				;offset for printing
                INT 21h
                
                MOV ah,01h			;Accepting Size
                INT 21h
                
                SUB al,30h
                MOV len,al      ;Storing size in variable

                MOV cl,len      ;Moving size in counter
                MOV ch,00
                
                LEA si,arr		  ;Setting pointer at initial position
							 
          loop1:MOV ah,09h      ;Message for accepting
                LEA dx,S2
                INT 21h
                
                MOV ah,01h			;Accepting array elements
                INT 21h
								
								MOV [si],al     ;Storing array elements
								
								INC si
								LOOP loop1
								
                LEA si,arr      ;Setting pointer at initial position
								
								MOV cl,len      ;Moving size in counter
								MOV ch,00
								
								MOV ah,09h      ;Output Message
                LEA dx,S3
                INT 21h
         				
         				MOV al,00

          loop2:MOV dl,[si]
          			ADD res,dl
                SUB res,30h
                
                INC si
                LOOP loop2      
                
                MOV ah,00
                MOV al,res
                DIV D
                
                ADD al,30h
                ADD ah,30h
                
                MOV Q,al
                MOV R,ah
                    
                MOV dl,Q
                MOV ah,2h				;Printing Result
                INT 21h
                
                MOV dl,R
                MOV ah,2h
                INT 21h
                
                MOV ah,4ch
                INT 21h
END
