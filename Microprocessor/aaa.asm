.model small
.stack 100H
.data 
.code

start:MOV CH,00H
      MOV AH,00H 
    MOV CL,07H
	MOV AL,04H
	ADD AL,CL
	AAA
mov ah,4ch
int 21h
End start
