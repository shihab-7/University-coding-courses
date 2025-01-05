;FOR loop in assembly


.MODEL SMALL
.STACK 100H
.DATA

MSG DB "HELLO$"


.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS, AX
    
    ;5 bar hello print korbe
    MOV BL,10
HERE:
    JE EXIT
    CMP BL,0
    MOV AH,9
    LEA DX, MSG
    INT 21H
    CALL NEWLINE
    DEC BL
    JMP HERE
    
EXIT:       
    
    
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP

    NEWLINE PROC
        
        MOV AH,2
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        RET
        NEWLINE ENDP

END MAIN