.model small
.stack 100h
.data
msg db 0dh,0ah,"Found At Position: $"
msg1 db 0dh,0ah,"Not Found: $"
array dw 1012h,1015h,1025h,1036h,1045h,1052h,1057h,1068h,1079h,1084h
key EQU 1084h
len dw ($-array)/2
pos dw 2 dup(?)
.code
start:MOV AX,@DATA
      MOV DS,AX 
	  MOV BX,key
	  MOV CX,0000H
	  MOV DX,len
loop1:CMP CX,DX
      JA NFOUND
      MOV AX,CX
	  ADD AX,DX
	  SHR AX,0001H
	  MOV SI,AX
	  ADD SI,SI
	  CMP BX,array[SI]
	  JAE loop2
	  DEC AX
	  MOV DX,AX
      JMP loop1
loop2:JE FOUND
      INC AX
      MOV CX,AX	
      JMP loop1
FOUND:INC AL
      ADD AL,'0'
      MOV AH,'0'
      LEA SI,pos 
	  MOV [SI],AX
	  INC SI
	  MOV[SI],'$'
      LEA DX,msg
	  MOV AH,09H
	  INT 21H
	  LEA DX,pos
	  MOV AH,09H
	  INT 21H
	  JMP FINISH
NFOUND:LEA DX,msg1
       MOV AH,09H
	   INT 21H
FINISH:MOV AH,4CH
       INT 21H
end start	   