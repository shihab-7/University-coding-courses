; ONLY VALID FOR 0-9 INTEGERS

;CHECK VALID TRIANGLE

.MODEL SMALL
.STACK 100H
.DATA

side_a DB 0
side_b DB 0
side_c DB 0

MSG1 DB "VALID$"
MSG2 DB "INVALID$"
MSG3 DB "Enter a,b,c : $"


.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, MSG3
    INT 21H
    
    CALL NEWLINE
    CALL INPUT
    MOV side_a,AL
    CALL NEWLINE
    CALL INPUT
    MOV side_b,AL
    CALL NEWLINE
    CALL INPUT
    MOV side_c,AL
    
    
    ;check if a+b > c
    MOV AL,side_a
    ADD AL,side_b
    CMP AL,side_c
    JLE INVALID
    
    ;check a+c > b
    MOV AL,side_a
    ADD AL,side_c
    CMP AL,side_b
    JLE INVALID
    
    ;check b+c > a
    MOV AL,side_b
    ADD AL,side_c
    CMP AL,side_a
    JLE INVALID
    
    ; IF VALID
    CALL NEWLINE
    MOV AH,9
    LEA DX,MSG1
    INT 21H
    JMP EXIT
    

INVALID:
    
    CALL NEWLINE
    MOV AH,9
    LEA DX,MSG2
    INT 21H
    JMP EXIT
    
    
EXIT:
    
    MOV AH, 4CH
    INT 21H    
    
    
    MAIN ENDP

    NEWLINE PROC
        MOV AH,2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        RET
        NEWLINE ENDP
    
    
    ;INPUT FUNCTION
    INPUT PROC
        
        MOV AH, 1
        INT 21H
        SUB AL,'0'
        RET
        INPUT ENDP

END MAIN