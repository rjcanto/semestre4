.intel_syntax noprefix
.data

.text
.global struprcnt

struprcnt:
	push 	ebp
	mov 	ebp, esp
	
	push 	ebx
	push	edi
	push	esi
	
	mov		esi,[ebp+8]
	xor		edi,edi
	
W:
	movzx	ebx, byte ptr[esi]
	test	bx,bx
	je		_ret
	
	push	ebx
	call	islower
	test	ax,ax
	je		_next
	call	toupper
	inc 	edi
	mov		[esi], al

_next:
	add 	esp, 4
	inc		esi
	jmp		W
	
_ret:
	mov		ebx,[ebp+12]
	mov		[ebx],edi
	mov		eax,[ebp+8]
	pop		edi
	pop		esi
	pop		ebx
	mov		esp,ebp
	pop		ebp
	ret


