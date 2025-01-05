.MODEL SMALL
.STACK 100H
.DATA 
response DW ?
msg1     DB "FOUND$"
msg2     DB "NOT FOUND$"
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV response, AX
    CALL NEWLINE
    
    MOV AX, response
    CMP AX, 404
    JE print_not_f
    
    MOV AH, 9
    LEA DX, msg1
    INT 21H
    JMP endl
    
print_not_f:
    MOV AH, 9
    LEA DX, msg2
    INT 21H
    
endl:
    CALL NEWLINE
    
    
exit:
    MOV AH,4CH
    INT 21H
 
 
MAIN ENDP

    INPUT PROC

      MOV CX,0 
inputF:
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
      JMP inputF
                    
    INPUT ENDP

    NEWLINE PROC
      MOV AH,2
      MOV DL,0AH
      INT 21H
      MOV DL,0DH
      INT 21H 
      RET  
    NEWLINE ENDP
    
END MAIN