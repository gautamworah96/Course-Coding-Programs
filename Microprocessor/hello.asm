.model small
.data
message DB "Tu cute hai$"
.code
START:
	MOV AX,@data
	MOV DS,AX
	MOV AH,09H
	MOV DX,offset message
	INT 21H
	MOV AH,4CH
	INT 21H
end START	