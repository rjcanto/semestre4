.intel_syntax noprefix
.data

.text
.global procStays

procStays:
	push 	ebp
	mov		ebp, esp
	
	push	edi
	push	esi
	push	ebx
	
	lea		ebx,[stays]
	lea		esi,[stays+4*10*4]
	
F:
	cmp		esi, ebx
	jae		_null		#<<< Check
	mov		edi,[ebx]
	test	edi,edi
	je		_next
	push	edi
	call	[ebp+8]
	add		esp,4
	test	eax,eax
	je		_next
	jmp		_end		#<<<

_next:
	add		esi,4		#<<<
	jmp		F

_end:
	mov		eax,[edi]	#<<<
	jmp		_ret
_null:
	xor 	eax,eax
_ret:
	pop		ebx
	pop		esi
	pop		edi
	/*mov 	esp,ebp		#<<<*/
	pop		ebp
	ret
