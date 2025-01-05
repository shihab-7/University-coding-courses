INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA

.CODE


; simple input output code

;MAIN FUNCTION eikhan theke code run shuru hoy
MAIN PROC
    
    MOV AX, @DATA ; data segment define kore deowa hoise
    MOV DS, AX ; j segment theke code start hobe oitar address DS a dite hoy
    
    MOV AH,1 ; AH er man 1 kore INT 21H call korle input ney
    INT 21H
    
    MOV BL, AL  ; input value always AL a thake pore somossa na howar jonno onno register a copy kore rakaha valo
    
    PRINTN " "  ; builtin newline
    
    MOV AH, 2   ; AH er maan 2 dile character output dey
    MOV DL, 0DH  ; 0DH carrage r 0AH newline er hex value
    INT 21H
    MOV DL, 0AH
    INT 21H      ; carrage return kore then newline print kora lage 
    
    ;amra chaile builtin newline function o use korte pari er jonno
    ; INCLUDE "EMU8086.INC" 1st a likhe jekhane newline nibo oikhane
    ; PRINTN " " dilei newline call hoye jabe
    
    
    ; input jeta nisi oita output
    
    MOV AH, 2  ; output a character dekhanor jonno AH er maan 2 kora 
    MOV DL, BL ; j kono kisu output korte DX or DL use kora must
    INT 21H    ; INT 21H call korlei output dibe
    
    MOV AH, 4CH ; system k akta value return kore main function sesh bujhanor jonno AH k 4CH value diye INT 21H call kora
    INT 21H
    
    
    MAIN ENDP
END MAIN
  
;USER : ISHAAN, KEY : 27R3VDEFYFX4N0VC3FRTQZX