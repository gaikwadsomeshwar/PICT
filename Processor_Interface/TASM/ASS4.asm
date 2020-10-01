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

            str1    db 25 DUP ('$')
            str2    db 25 DUP ('$')
            len1    db 0
            len2    db 0
            menu    db '1. Compare',13,10,'2. Concatenate',13,10,'3. Substring',13,10,'4. Exit',13,10,'Your Choice : $'
            msg1    db 'Enter String: $'
            msg6    db 13,10,13,10,'Incorrect Choice$'
            newline db 13,10,13,10,'$'
            choice  db ?

.code

        MAIN PROC

            init
            LEA dx,msg1
            prints
            LEA si,str1
            CALL ACCEPT
            MOV len1,cl

            LEA dx,msg1
            prints
            LEA si,str2
            CALL ACCEPT
            MOV len2,cl

            extrn SUBSTRING:FAR
            extrn STRCMP:FAR
            extrn STRCAT:FAR

            loop1:LEA dx,menu
            prints

            acceptch
            MOV choice,al
            SUB choice,30h

            CALL SWITCH
            JMP loop1

            ret
        ENDP

            SWITCH PROC

      case1:CMP choice,1
            JNE case2

            LEA si,str1
            LEA di,str2
            MOV al,len1
            MOV bl,len2
            CALL STRCMP
            LEA dx,newline
            prints
            ret

      case2:CMP choice,2
            JNE case3

            LEA si,str1
            LEA di,str2
            MOV dx,di

            MOV cl,len1
            MOV ch,len2

            CALL STRCAT
            LEA dx,newline
            prints
            ret

      case3:CMP choice,3
            JNE case4

            LEA si,str1
            LEA di,str2

            CALL SUBSTRING
            LEA dx,newline
            prints
            ret

      case4:CMP choice,4
            JNE default
            terminate

    default:LEA dx,msg6
            prints
            LEA dx,newline
            prints
            ret

        ENDP

        ACCEPT PROC

            MOV dl,[si]
            MOV cl,0
    label1: acceptch
            MOV [si],al
            INC cl
            INC si
            CMP al,13
            JNE label1

            ret
        ENDP

end
