.MODEL SMALL
.STACK 100H
.DATA
msg1 db "Messi$"
msg2 db "Ronaldo$"
msg3 db "Equal$"
a dw ?
b dw ?
x dw ?
y dw ?
p_m dw ?
p_r dw ?

.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV a,AX
    CALL NEWLINE
    CALL INPUT
    MOV b,AX
    CALL NEWLINE
    CALL INPUT
    MOV x,AX
    CALL NEWLINE
    CALL INPUT
    MOV y,AX
    
    MOV AX,a
    MOV BX,2
    MUL BX
    ADD AX,b
    MOV p_m,AX
    MOV AX,x
    MOV BX,2
    MUL BX
    ADD AX,y
    MOV p_r,AX
    
    MOV AX,p_m
    CMP AX,p_r
    JG messi
    JL ronaldo
    JE equal
    
messi:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg1
    INT 21H
    JMP exit
ronaldo:
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg2
    INT 21H
    JMP exit
equal:
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