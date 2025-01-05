.MODEL SMALL
.STACK 100H
.DATA
iq dw ?
msg1 db "Yes$"
msg2 db "No$"
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV iq,AX
    CALL NEWLINE
    
    MOV AX,iq
    ADD AX,7
    CMP AX,170
    JG p_y
    
    MOV AH,9
    LEA DX,msg2
    INT 21H
    JMP exit
    
p_y:
    MOV AH,9
    LEA DX,msg1
    INT 21H    
    
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