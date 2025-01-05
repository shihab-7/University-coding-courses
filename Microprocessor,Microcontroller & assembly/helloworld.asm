.model small
.data

str1 DB "Hello World !$"


.stack 100h
.code

main proc
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, str1
    INT 21H
    
    call newline
    MOV AH, 4CH
    INT 21H
main endp

newline proc
    
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    RET
newline endp
    

end main

