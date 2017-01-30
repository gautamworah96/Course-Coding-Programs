.model small
.stack 100H
.data
array db 21H,65H,45H,78H,98H
.code
start:	
	mov ax,@data
	mov ds,ax			
	mov ax,5000H			
	mov es,ax			
	mov cl,05H			
	lea si,array			
	mov di,0000H	
	back:	
		mov ax,[si]				
		mov es:[di],ax				
		inc si				
		inc di				
		loop back
	mov aH,4cH
	int 21H
	END start
