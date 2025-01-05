.MODEL SMALL
.STACK 100H
.DATA
msg1 db "YES$"
msg2 db "NO$"
x dw ?
n dw ?
m dw ?
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV x,AX
    CALL NEWLINE
    CALL INPUT
    MOV n,AX
    CALL NEWLINE
    CALL INPUT
    MOV m,AX
    
    MOV AX,x
    ADD AX,m
    
    CMP AX,n
    JGE p_y
    JMP p_n
    
p_y:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg1
    INT 21H
    JMP exit
p_n:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg2
    INT 21H
    JMP exit

exit:
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP

    NEWLINE PROC
        MOV AH,2
        MOV DL,0DH
        INT 21H
        MOV DL,0AH
        INT 21H
        RET
    NEWLINE ENDP
    
    INPUT PROC
        MOV CX,0
    in_put:
        MOV AH,1
        INT 21H
        CMP AL,13
        JNE calc
        MOV AX,CX
        RET
    calc:
        SUB AL,48
        MOV AH,0
        MOV BX,AX
        MOV DX,10
        MOV AX,CX
        MUL DX
        ADD AX,BX
        MOV CX,AX
        JMP in_put
     INPUT ENDP
END MAIN