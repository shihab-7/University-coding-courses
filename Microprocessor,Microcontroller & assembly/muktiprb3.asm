.MODEL SMALL
.STACK 100H
.DATA 
 total_days  DW 7
 rainy_days  DW ?
 cloudy_days DW ?
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    CALL INPUT
    MOV rainy_days, AX
    
    CALL NEWLINE
    
    CALL INPUT
    MOV cloudy_days, AX
    
    MOV AX, total_days
    SUB AX, rainy_days
    SUB AX, cloudy_days
    MOV BX, AX
    
    CALL NEWLINE
    MOV AX,BX
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