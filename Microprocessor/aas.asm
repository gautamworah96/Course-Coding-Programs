.model small
.stack 100H
.data 
.code

start: 
MOV CH,00H
MOV AH,00H
MOV CL,37H
MOV AL,33H
SUB AL,CL
AAS
mov ah,4ch
int 21h
End start
