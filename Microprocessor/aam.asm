.model small
.stack 100H
.data 
.code

start:
    MOV AX,0000H
    MOV AL,08H
	MOV CH,00H
	MOV CL,03H
	MUL CL
	AAM
MOV AH,4CH
INT 21H
End start
