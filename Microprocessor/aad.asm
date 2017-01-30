.model small
.stack 100H
.data 
.code

start:  
    MOV AX,1500H
	MOV BH,00H
	MOV BL,50H
	DIV BL
	AAD
MOV AH,4CH
INT 21H
End start
