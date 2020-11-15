.model small
.stack 100h
.data
                arr  db 100 DUP(?)
                len  db ?
                endl db 13,10,'$'
                S1   db 13,10,'Enter Value:$',13,10
                S2   db 13,10,'Values:$',13,10

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

								MOV al,len
                MOV cl,al      ;Moving size in counter
                MOV ch,00
                
                LEA si,arr		  ;Setting pointer at initial position
							 
          loop1:MOV ah,09h      ;Message for accepting
                LEA dx,S1
                INT 21h
                
                MOV ah,01h			;Accepting array elements
                INT 21h
								
								MOV [si],al     ;Storing array elements
								
								INC si
								LOOP loop1
								
                LEA si,arr      ;Setting pointer at initial position
								
								MOV al,len
								MOV cl,al       ;Moving size in counter
								MOV ch,00
								
								MOV ah,09h      ;Output Message
                LEA dx,S2
                INT 21h

          loop2:MOV dl,[si]     
                MOV ah,2h				;Printing array elements
                INT 21h
                
                LEA dx,endl     
                MOV ah,09h			;Printing next line
                INT 21h
                
                INC si
                LOOP loop2
                
                MOV ah,4ch
                INT 21h
END
