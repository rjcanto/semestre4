/*
----------------------------------------------------------------------
Nome:		Nuno Alexandre Cancelo
Numero:		31401
Turma:		LI31N
Semestre:	Inverno 2009/2010 (Época Especia)
----------------------------------------------------------------------
*/
/*
1. A partir do código fonte em anexo, implemente em assembly IA32 a 
função readline() declarada no ficheiro readline.h, chamando apenas a 
função getchar() da biblioteca standard, por forma a que o programa 
cmdDemo seja gerado a partir do makefile e funcione correctamente.
*/

.intel_syntax noprefix
.text
.global readline

.equ INT,4
.equ BYTE,1
/* char * readline(char *ln, int max);*/

readline:
	push ebp
	mov ebp, esp
	push ebx
	push edi
	mov edi, [ebp+12]
	mov ebx,[ebp+8]
_do:
	test edi,edi
	je _end
	call getchar

	cmp al,-1
	jz _retnull
	
	cmp al, '\n'
	jz _end

	cmp al, '\r'
	jz _end

	cmp al, '\0'
	jz _end

	
	mov [ebx],al
	inc ebx
	dec edi
	jmp _do
_end:
	mov byte ptr[ebx],0
	mov eax, [ebp+8]
	jmp _return
_retnull:
	xor eax,eax
_return:
	pop edi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
