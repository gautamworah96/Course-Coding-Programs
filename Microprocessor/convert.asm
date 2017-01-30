.model small
.stack 100H
.data 
msg1 DB 0DH,0AH, "Enter a String: $"
msg2 DB 0DH,0AH, "Converted String is: $"
str1 DB 255 DUP(?)
.code
START:
	MOV AX,@data
	MOV DS,AX
	LEA DX,msg1
	MOV AH,09H
	INT 21H
	LEA SI,str1
	MOV AH,01H
	READ:
		INT 21H
		CMP AL,0DH
		JE DISPLAY
		XOR AL,20H
		MOV [SI],AL
		INC SI
		JMP READ
	DISPLAY:
		MOV AL,'$'
		MOV [SI],AL
		LEA DX,msg2
		MOV AH,09H
		INT 21H
		LEA DX,str1
		MOV AH,09H
		INT 21H
		MOV AH,4CH
		INT 21H
end START