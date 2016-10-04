global _add

[section .text]

	_add:
		push ebp
		mov ebp, esp
				; la llamada se hara _add( op1 , op2, &variable)
		mov al, byte [ebp+4] ;  &variable =eax

		add al , 0xff
		mov byte [ebp+4] , al


		
		
		
		pop ebp
		leave
		ret
