.intel_syntax noprefix
.data

.text
.global longest_match


longest_match:

	push 	ebp
	mov		ebp,esp
	
	push	ebx
	push 	edi
	push	esi
	
	mov		ebx, [ebp+12]
	mov		esi, [ebp+8]
	xor		edi,edi
	xor		eax,eax
	push	eax
	
W:
	test	ebx,ebx
	je		_ret
	push	[ebp+16]
	push	[esi]
	call	strspn
	add		esp,8
	pop		ecx
	
	cmp		eax,ecx
	jbe		_next
	mov		edi,[esi]
	push	eax

_next:
	add 	esi,4
	dec		ebx
	jmp W

_ret:
	add 	esp,4
	mov		eax,edi
	pop		esi
	pop		edi
	pop		ebx
	mov		esp,ebp
	pop		ebp
	ret
	
