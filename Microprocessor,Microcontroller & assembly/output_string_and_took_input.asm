INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA  

;data section a all variables declare kora hoy

STR1 DB "Enter a character : $"
STR2 DB "You entered : $"


.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    
    ; printing string 1
    MOV AH, 9
    LEA DX, STR1
    INT 21H
    
    ;taking input
    MOV AH, 1
    INT 21H
    
    
    ; copied the input in other register because for every output AL flash automatically
    MOV BL, AL
    
    PRINTN " " ; builtin newline function
    
    
    ;printion string 2
    MOV AH, 9
    LEA DX, STR2
    INT 21H
    
    CALL NEWLINE ; calling user defined newline function
    
    ;printing the inputted value
    MOV AH, 2
    MOV DL, BL
    INT 21H
    
    ; returning control to the system
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP

    ; newline user defined function
    NEWLINE PROC
        
        MOV AH, 2
        MOV DL, 0DH
        INT 21H
        MOV DL, 0AH
        INT 21H
        RET
        
    NEWLINE ENDP




END MAIN