
; CHECK A CHAR IS SMALL OR CAPITAL OR INVALID

.MODEL SMALL
.STACK 100H
.DATA

STR1 DB "SMALL$"
STR2 DB "CAPITAL$"
STR3 DB "Enter a char : $"
STR4 DB "INVALID$"


.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, STR3
    INT 21H
    
    MOV AH, 1
    INT 21H
    
    ;if char >= A and <=Z
    CMP AL,'A'
    JL ELSE    
    CMP AL, 'Z'
    JLE label2
    
    ;else if char >=a and <=z
    
    CMP AL, 'a'
    JL ELSE    
    CMP AL, 'z'
    JLE label1 
         
ELSE:
    CALL NEWLINE
    MOV AH, 9
    LEA DX, STR4
    INT 21H
    JMP EXIT
               
label1:
    
    CALL NEWLINE
    MOV AH, 9
    LEA DX, STR1
    INT 21H
    JMP EXIT
    
label2:
    
    CALL NEWLINE
    MOV AH, 9
    LEA DX, STR2
    INT 21H
       
EXIT:

    CALL NEWLINE        
    MOV AH, 4CH
    INT 21H
    
    
    MAIN ENDP

    NEWLINE PROC
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        RET
    NEWLINE ENDP


END MAIN