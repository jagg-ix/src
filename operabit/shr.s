segment .text	

global _shr:
	pop dl ; *ptrVariable
	pop al ;  numeroRecorrido 
	mov  cl, byte  [dl]  ; guarda el contenido del  byte apuntado 
	shr cl , al ; hace el corrimiento
	mov byte [dl] , cl 
	ret
	
	
