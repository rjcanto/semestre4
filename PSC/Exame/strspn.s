.intel_syntax noprefix
.data

.text
.global strspn

strspn:
	push	ebp
	mov		ebp,esp

	push	esi
	push	edi
	push	ebx
	
	xor eax,eax
	
	mov edi,[ebp+8]
	mov esi,[ebp+12]
	
F:
	xor ebx,ebx
	movzx ecx,byte ptr[edi]
	test cx,cx
	je _ret
	
W:
	movzx edx,byte ptr[esi]
	test dx, dx
	je _ret
	
	cmp cx,dx
	jz _next
	inc esi
	inc ebx
	jmp W
_next:
	inc ax
	inc edi
	sub esi,ebx
 	jmp F

_ret:
	pop ebx
	pop edi
	pop esi
	mov esp,ebp
	pop ebp
	
	ret
	
	
