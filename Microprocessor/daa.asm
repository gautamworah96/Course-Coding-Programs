.model small
.stack 100H
.data
.code
start:
MOV CH,00H
MOV AH,00H
mov CL,08H
mov AL,08H
add AL,CL
daa
MOV AH,4CH
INT 21H
End start