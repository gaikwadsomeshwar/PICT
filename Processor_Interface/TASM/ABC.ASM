.model small
.stack 100h
;.data
.code
                mov ax,@data  ;To be used when data segment is used
                mov ds,ax

               ;  mov ah,01h  ;Read a character from Keyboard
               ;  int 21h

               ; mov dx,'A'  ;Store character of ASCII 41 in dl Register

                mov ah,02h  ;Display Character from Data Register
                mov dx,41h
                int 21h

                mov ah,04ch  ;Terminate the Program
                int 21h
end


