.MODEL SMALL
.STACK 100H
.DATA
 	MSG1 DB 0DH,0AH, "ENTER A NUMBER: $"
	MSG2 DB 0DH,0AH, "THE NUMBER YOU ENTERED IS POSITIVE $"
	MSG3 DB 0DH,0AH, "THE NUMBER YOU ENTERED IS NEGATIVE $"
.CODE
	START:
		MOV AX,@DATA
		MOV DS,AX
		LEA DX,MSG1
		MOV AH,09H
		INT 21H
		MOV AH,01H
		INT 21H
		MOV BL,AL
	READ:
		INT 21H
		CMP AL,0DH
		JE CHECK
		JMP READ
	CHECK:
		MOV AL,BL
		CMP AL,'-'
		JNZ POS

		LEA DX,MSG3
		MOV AH,09H
		INT 21H
		JMP FINISH
	POS:
		LEA DX,MSG2
		MOV AH,09H
		INT 21H
	FINISH:
		MOV AH,4CH
		INT 21H
END START