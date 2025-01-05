     .MODEL SMALL
.STACK 100H
.DATA
x dw ?
y dw ?

.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV x,AX
    CALL NEWLINE
    CALL INPUT
    MOV y,AX
    
    CALL NEWLINE
    MOV AX,x
    SUB AX,y
    CALL OUTPUT
    
exit:
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
    
    NEWLINE PROC    ; newline function
        MOV AH,2
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        RET
        NEWLINE ENDP
    
    INPUT PROC      ; input function, val in ax

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

    OUTPUT PROC     ; output function, val in ax
          
    XOR CX,CX
print:
  
      MOV DX,0
      MOV BX,10
      DIV BX 
      PUSH DX 
      INC CX
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
END MAIN