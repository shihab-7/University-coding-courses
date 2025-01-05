.MODEL SAMLL
.STACK 100H
.DATA

STR1 DB "Enter 1st number : $"
STR2 DB "Enter 2nd number : $"
STR3 DB "Addition : $"
STR4 DB "Substraction : $"
VAR1 DB 0
VAR2 DB 0
ADDITION DB 0
MULTIPLICATION DB 0
DIVISION DB 0


.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    ;print ENTER 1ST NUM
    MOV AH, 9
    LEA DX, STR1
    INT 21H
    
    ;Took input and convert in decimal, store in var1
    MOV AH, 1
    INT 21H
    SUB AL, '0'
    MOV VAR1, AL
    
    CALL NEWLINE
      
    ;print enter 2nd num          
    MOV AH, 9
    LEA DX, STR2
    INT 21H
    
    
    ;took input and convert in decimal , store in var2
    MOV AH, 1
    INT 21H
    SUB AL,'0'
    MOV VAR2, AL
    
    CALL NEWLINE
    
    ;print addition
    MOV AH, 9
    LEA DX, STR3
    INT 21H
    
    ;add var1 and var2
    MOV AL, VAR1
    ADD AL, VAR2
    ADD AL, '0'
    
    ;output add result
    MOV AH, 2
    MOV DL, AL
    INT 21H
    
    CALL NEWLINE
    
    ;PRINT SUBSTRACTION
    MOV AH, 9
    LEA DX, STR4
    INT 21H
    
    ;SUBTRACT VAR1, VAR2
    MOV AL, VAR1
    SUB AL, VAR2
    ADD AL, '0'
    
    ;PRINT SUBSTRACTION RESULT
    MOV AH, 2
    MOV DL, AL
    INT 21H
    
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