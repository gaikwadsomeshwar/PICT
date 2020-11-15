.model small
.stack 100h
.data

                abc db 'Hello World',13,10,'PICT$'

.code

                mov ax,@data
                mov ds,ax

                mov ah,09h
               ; mov dx,OFFSET abc
                lea dx,abc
                int 21h

                mov ah,04ch
                int 21h

end

