.model small
.stack 100h
.data

                A db '9'
                B db '3' 
                Q db 0Ah
                R db ?

.code

                MOV ax,@data
                MOV ds,ax
                
                SUB A,30h
                SUB B,30h
                
                MOV al,A       ;Moving contents of variable A to al register
                MOV bl,B       ;Moving contents of variable B to bl register
                
                ADD bl,al      ;Add contents of bl and al and store in bl
                MOV dl,bl
                
                MOV al,bl
                MOV ah,00
                DIV Q

                ADD al,30h
                ADD ah,30h

                MOV Q,al
                MOV R,ah

                MOV dl,Q
                MOV ah,02h
                INT 21h

                MOV dl,R
                MOV ah,02h
                INT 21h

                MOV ah,04ch
                INT 21h

end
