init macro
    MOV ax,@data
    MOV ds,ax
endm

prints macro
    MOV ah,09h
    INT 21h
endm

acceptch macro
    MOV ah,01h
    INT 21h
endm

printch macro
    MOV ah,02h
    INT 21h
endm

terminate macro
    MOV ah,04ch
    INT 21h
endm

.model small
.stack 100h
.data

              cat     db 25 DUP ('$')
              msg4    db 13,10,13,10,'Result      : $'

.code

          PUBLIC STRCAT
          STRCAT PROC FAR

              LEA di,cat
              SUB cl,1

      label2: MOV al,[si]
              MOV [di],al
              INC si
              INC di
              DEC cl
              CMP cl,0
              JNE label2

              MOV si,dx
              SUB ch,1

      label4: MOV al,[si]
              MOV [di],al
              INC si
              INC di
              DEC ch
              CMP ch,0
              JNE label4

              LEA dx,msg4
              prints

              LEA dx,cat
              prints
              ret

          STRCAT ENDP	
end
