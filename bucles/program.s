global main
extern printf

[section .text]
 main:
	push ebp
	push esp
	push ebx
	push esi
	push edi
	
	mov ebp,esp
		
		mov ecx, 10
	
	while:
		push dword mensaje
		call printf
		add  esp, byte 4 
		sub ecx,1
		cmp ecx,5		
		jnz while		
	
	
		
		
	
	mov eax,0

	pop edi
	pop esi
	pop ebx
	pop esp
	pop ebp
	ret
[section .data]
	mensaje db "numero de incrementos y vueltas ",13,10,0


[section .bss]
	incremento resb 1
	sumatoria  resb 1
