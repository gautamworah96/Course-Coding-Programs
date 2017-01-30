.model small
.stack 100H
.data
.code
start:
MOV CH,00H
MOV AH,00H
mov CL,03H
mov AL,0FH
SUB AL,CL
DAS
MOV AH,4CH
INT 21H
End start