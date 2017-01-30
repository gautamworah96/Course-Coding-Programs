.model small
.stack 100
.data
MSG DB 20 DUP('$')
.code
start:
MOV AX,@data
MOV DS,AX
MOV AH,00H
MOV AL,03H
INT 10H
MOV AH,02H
MOV DX,00H
MOV BX,00H
INT 10H
LEA SI,MSG
ENTER:
MOV AH,01H
INT 21H
CMP AL,0DH
JZ ACCEPT
MOV [SI],AL
INC SI
JMP ENTER
ACCEPT:
MOV AL,'$'
MOV [SI],AL
MOV DX,0A1CH     ;set cursor at centre
MOV BH,00H
MOV AH,02H
INT 10H
LEA SI,MSG
DISPLAY:
MOV AL,[SI]
CMP AL,'$'
JZ FINISH
MOV BH,00H
MOV BL,0F4H     
MOV CX,01H      
MOV AH,09H
INT 10H
INC SI
MOV AH,02H  
INC DL
INT 10H
JNZ DISPLAY
FINISH:
MOV AH,4CH
INT 21H
END start