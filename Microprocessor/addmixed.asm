

.MODEL small, C
.CODE
PUBLIC Addnum
Addnum PROC NEAR USES BX, x: WORD, y: WORD
MOV AX, x
ADD AX, y
RET
Addnum ENDP
END

