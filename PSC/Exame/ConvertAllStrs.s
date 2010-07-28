.intel_syntax noprefix
.data

.text
.global ConvertAllStrs

ConvertAllStrs:
	push 	ebp
	mov		ebp,esp
	
	push 	ebx
	push	edi
	push	esi
	
	mov		ebx,[ebp+12]
	mov		esi,[ebp+8]
	xor		edi,edi

W:
	test 	ebx, ebx
	je		_ret
	push	[esi]
	push	[esi+4]
	call	[ebp+16]
	add		esp,8
	add		edi,[esi]
	dec		ebx
	add		esi,8
	jmp		W
	
_ret:
	mov		eax,[edi]
	pop		edi
	pop		esi
	pop		ebx
	mov		esp,ebp
	pop		ebp
	ret
