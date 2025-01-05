.model small
.stack 100h
.data 

c dw 1
n dw ?
t dw 1 
 
.code
main proc
mov ax,@data
mov ds,ax 

call in1
mov n,ax
call newline
l:
cmp n,0
je ex
l1:
cmp n,0
je  exit2
mov ax,c
add ax,t 
mov c,ax
inc t
dec n
jmp l1

exit2:
mov ax,c
call out1
jmp exit1




  
mov ax,cx
call out1

ex:
mov ah,2
mov dl,48
INT 21h
 
exit1:
mov ah,4ch
INT 21h
 
 
main endp  
 in1 proc

  mov cx,0 
  input:
  mov ah,1
  int 21h
  cmp al,13
  jne calc 
  mov ax,cx    ;input in ax 
  ;xor cx,cx     ;clear cx for store count value
 ; jmp print 
 ret
  
  calc:  
  sub al,48
  mov ah,0
  mov bx,ax    ;input in bx
  
  mov dx,10
  mov ax,cx    ;for mul copy cx to ax
  mul dx        ;ax=ax*dx
  add ax,bx     ;ax=ax+bx    a=0*10+input
                            ; a=a*10+input
  mov cx,ax  
  jmp input
             
             ;now input in ax
                    
in1 endp

out1 proc
             
             ;now input in ax  
  xor cx,cx
  print:
  
  mov dx,0
  mov bx,10
  div bx      ;ax=ax/10  dx=ax%10
  push dx 
  inc  cx
  cmp ax,0
  jne print 
   
  
  
  printf:
  mov ah,2
  pop dx
  add dl,48
  int 21h
  loop printf 
  
  ret
                    
out1 endp

newline proc
  mov ah,2
  mov dl,10
  int 21h            ;new line
  mov dl,13
  int 21h 
  ret  
newline endp    
end main