global _add
extern printf
[section .text]

	_add:
		push ebp
		push esp
		mov ebp, esp
		
		mov eax ,dword [ebp+12] ; primer parametro
		mov ecx , dword [ebp+12+4] ; segundo parametro
		add eax, ecx	; eax+=ecx
		pop esp
	   	pop ebp	
		ret

[section .data]
	mensajeContenido db " el contenido del primer parametro es %s \n",0 
	
