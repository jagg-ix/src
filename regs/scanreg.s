global  scanreg
section .text

scanreg:
	push ebp
	mov ebp,esp
	mov edx , 0x0ffefff0
	mov eax, edx
	pop  ebp
	ret
