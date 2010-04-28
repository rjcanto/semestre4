/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/

.intel_syntax noprefix

.text
.global astrcat

astrcat:
	push ebp
	mov ebp,esp
	push ebx
	push edi
	push esi
	
	mov edi,[ebp+8]

_forstr1:
	movzx ebx,byte ptr[edi]
	test bl,bl
	je _befforstr2
	inc edi
	jmp _forstr1
	
_befforstr2:
	mov esi,[ebp+12]	
	dec edi

_forstr2:
	movzx ebx,byte ptr[esi]
	test bl,bl
	je _end
	mov byte ptr[edi], bl
	inc esi
	inc edi
	jmp _forstr2
	
_end:
	mov byte ptr[edi], 0
	mov eax,[ebp+8]
	pop esi
	pop edi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	
	
	
