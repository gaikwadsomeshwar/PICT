.model small
.stack 100h
.data
                msg db 'Numbers are:$',13,10

.code

                MOV ax,@data
                MOV ds,ax

                MOV cx,10
                MOV dl,48
                MOV ah,02h
         loop1: INT 21h

                INC dl
                DEC cx
                JNZ loop1

                MOV ah,4ch
                INT 21h
END
