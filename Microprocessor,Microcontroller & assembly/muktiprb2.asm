.MODEL SMALL
.STACK 100H
.DATA 
str DB 10 dup("?")
lucky_letter DB "?", "$"


.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX, str
    CALL READ_STR
    
    LEA SI, str
    MOV AL, [SI+6]
    MOV lucky_letter, AL
    
    CALL NEWLINE
    
    MOV AH,9
    LEA DX, lucky_letter
    INT 21H
    
exit:
    MOV AH,4CH
    INT 21H
 
 
MAIN ENDP

    READ_STR PROC
        MOV CX, 10
        LEA DI, str
    input_loop:
        MOV AH, 1
        INT 21H
        MOV [DI], AL
        INC DI
        LOOP input_loop
        RET
    READ_STR ENDP

    NEWLINE PROC
      MOV AH,2
      MOV DL,0AH
      INT 21H
      MOV DL,0DH
      INT 21H 
      RET  
    NEWLINE ENDP
    
END MAIN