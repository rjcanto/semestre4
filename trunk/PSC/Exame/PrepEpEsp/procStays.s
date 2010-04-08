.intel_syntax noprefix
.text
.global procStays:

	push ebp
	mov ebp,esp
	sub esp, 12 /*Stay *s*/
	
	push ebx
	push esi
	push edi
	
	lea ebx,[stays];
	add edi, ebx+FLOORS*ROOMS
	
_for:
	cmp ebx,edi
	jae _endFor
	mov esi,[ebx]
	push esi
	call ebp+8
	add esp,4
	and eax,esi
	je _end
	add ebx,12
	jmp _for
	
	
_endFor:
	xor eax,eax
	jmp _end
_end:
	pop edi
	pop esi
	pop ebx
	add esp,12
	mov esp,ebp
	pop ebp
	ret
	
	
	
