/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/

/* 
void * ssearch (
	+8		const void * key, 
	+12		const void * base, 
	+16		size_t size,
	+20		size_t elem_size, 
	+24		int (* compare)(const void * k, const void * key)
);
*/

.intel_syntax noprefix
.data

.global ssearch

ssearch:
	push 	ebp
	mov 	ebp,esp
	
	push	ebx
	push	edi

	mov		ebx,[ebp+12]
	mov		edi,[ebp+16]

for:
	test	edi,edi
	jz _resetEax

	push	[ebp+8]	
	push	ebx
	call	[ebp+24]
	add		esp,8
	
	test 	eax, eax
	jnz		_loadEax
	
	dec 	edi
	add		ebx,[ebp+20]
	jmp for
	
_loadEax:
	mov 	eax,ebx
	jmp		_fim
_resetEax:
	xor 	eax,eax
_fim:
	pop edi
	pop ebx
	pop ebp
	ret
