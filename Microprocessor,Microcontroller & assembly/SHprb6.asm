.MODEL SMALL
.STACK 100H
.DATA
msg1 db "GOLD$"
msg2 db "SILVER$"
msg3 db "BRONZE$"
x dw ?
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV x,AX
    
    MOV AX,x
    CMP AX,3
    JL gold
    CMP AX,6
    JL silver
    JMP bronze
    
gold:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg1
    INT 21H
    JMP exit
silver:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg2
    INT 21H
    JMP exit
bronze:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg3
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