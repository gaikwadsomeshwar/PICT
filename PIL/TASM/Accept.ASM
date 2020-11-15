.model small
.stack 100h
.data

                A db ?
                B db ? 
                S1 db 13,10,'Operand : $',13,10,13,10
                S2 db 13,10,'Addition : $',13,10,13,10

.code

                MOV ax,@data
                MOV ds,ax

                MOV ah,09h      ;Message for accepting
                LEA dx,S1
                INT 21h
                
                MOV ah,01h			;Accepting
                INT 21h
                
                MOV A,al
                
                MOV ah,09h      ;Message for accepting
                LEA dx,S1
                INT 21h
                
                MOV ah,01h			;Accepting
                INT 21h
                
                MOV B,al
                
                MOV al,A       ;Moving contents of variable A to al register
                MOV bl,B       ;Moving contents of variable B to bl register
                
                ADD bl,al      ;Add contents of al and bl and store in al
								SUB bl,30h     ;Logic for getting correct value
                
                MOV ah,09h     ;Message for Output
                LEA dx,S2
                INT 21h
                
                MOV dl,bl       ;Displaying Result
                MOV ah,02h
                INT 21h

                MOV ah,04ch
                INT 21h

end
