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

              msg2    db 13,10,13,10,'Equal$'
              msg3    db 13,10,13,10,'Not Equal$'

.code

          PUBLIC STRCMP
          STRCMP PROC FAR

              CMP al,bl
              JNE label5

              MOV cl,al
              SUB cl,1

      label3: MOV al,[si]
              MOV bl,[di]
              CMP al,bl
              JNE label5
              INC si
              INC di
              DEC cl
              CMP cl,0
              JNE label3

              LEA dx,msg2
              prints
              ret

      label5: LEA dx,msg3
              prints
              ret

          STRCMP ENDP		
end
