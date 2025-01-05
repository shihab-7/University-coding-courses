.MODEL SMALL
.STACK 100H
.DATA 
msg_y DB "YES$"
msg_n DB "NO$"
score DW 0
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    CALL INPUT
    MOV score, AX
    
    MOV AX, score
    CMP AX, 12
    JGE qualified
    JMP not_qualified
    
qualified:
    CALL NEWLINE
    MOV AH, 9
    LEA DX, msg_y
    INT 21H
    JMP exit

not_qualified:
    CALL NEWLINE
    MOV AH, 9
    LEA DX, msg_n
    INT 21H

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