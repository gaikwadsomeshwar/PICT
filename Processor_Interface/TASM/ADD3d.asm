.model small
.stack 100h
.data

                A dw 215
                B dw 125 
                D dw 0Ah
                R dw ?
								Q dw ?
								X dw ?
								Y dw ?
								Z dw ?
.code

                MOV ax,@data
                MOV ds,ax                
                
                MOV ax,A       ;Moving contents of variable A to al register
                MOV bx,B       ;Moving contents of variable B to bl register
                
                ADD al,bl      ;Add contents of bl and al and store in al
								MOV ah,00
								ADC ah,0
                
                DIV D
                
                MOV Q,ax
                MOV X,dx
                MOV dx,0h
               	MOV ax,0h
                MOV ax,Q
                
                DIV D
             		
                MOV Q,ax
                MOV Y,dx
                MOV dx,0h
               	MOV ax,0h
                MOV ax,Q
             		
                DIV D
                
                MOV Q,ax
                MOV Z,dx
                MOV dx,0h
               	MOV ax,0h
                MOV ax,Q
                
                MOV dx,Z
                MOV ah,02h
                INT 21h

                MOV dx,Y
                MOV ah,02h
                INT 21h

                MOV dx,X
                MOV ah,02h
                INT 21h
                
                MOV ah,04ch
                INT 21h

end
