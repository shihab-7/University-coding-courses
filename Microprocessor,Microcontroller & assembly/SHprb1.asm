.MODEL SMALL
.STACK 100H
.DATA
team_size dw ?
msg1  db "YES$"
msg2  db "NO$"


.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INPUT
    MOV team_size,AX
    
    MOV BX,team_size
    CMP BX,6
    JL print_no
    CMP BX,8
    JG print_no
    
    CALL NEWLINE
    MOV AH,9
    LEA DX,msg1
    INT 21H
    JMP exit
    
print_no:
    CALL NEWLINE 
    MOV AH,9
    LEA DX,msg2
    INT 21H    
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

END MAIN