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

            freq    db 0
            msg5		db 13,10,13,10,'Frequency   : $'

.code

        PUBLIC SUBSTRING
        SUBSTRING PROC FAR

            MOV bx,di
            MOV dx,si

    label6: MOV al,[si]
            CMP al,[di]
            JE  label7
            JMP label8

    label7: INC di
            INC si
            MOV cl,[di]
            CMP cl,13
            JE label9
            JMP label6

    label8: MOV di,bx
            MOV si,dx
            INC si
            MOV dx,si

            MOV cl,[si]
            CMP cl,13
            JNE label6
            JMP label10

    label9: INC freq
            JMP label8

    label10:LEA dx,msg5
            prints
            MOV dl,freq
            ADD dl,30h
            printch
            ret

            SUBSTRING ENDP
end
