.MODEL SMALL
.STACK 100H
.DATA 
current_rent DW ?
final_rent   DW ?
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    CALL INPUT
    MOV current_rent, AX
    
    MOV AX, current_rent
    MOV BX, 2
    MUL BX
    MOV final_rent, AX
    
    CALL NEWLINE
    MOV AX, final_rent
    CALL OUTPUT

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
    
    OUTPUT PROC    
               
      XOR CX,CX
print:
      
      MOV DX,0
      MOV BX,10
      DIV BX
      PUSH DX 
      INC  CX
      CMP AX,0
      JNE print
      
printf:
      MOV AH,2
      POP DX
      ADD DL,48
      INT 21H
      LOOP printf 
      
      RET
                    
    OUTPUT ENDP

    NEWLINE PROC
      MOV AH,2
      MOV DL,0AH
      INT 21H
      MOV DL,0DH
      INT 21H 
      RET  
    NEWLINE ENDP
    
END MAIN