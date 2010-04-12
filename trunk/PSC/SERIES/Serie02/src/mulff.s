/* int mulff(float *res, float a, float b); */

.intel_syntax noprefix
.data


.text
.global mulff
.equ _EXP_MASK, 0x7F800000
.equ _SIG_MASK, 0x80000000
.equ _MAT_MASK, 0x007FFFFF
.equ _EXP_BIAS_MASK, 0x0000007F
.equ _MAT_SIZE, 23
.equ _MAT_CORR_MASK, 0x800000

mulff:
	push ebp
	mov ebp,esp
	push ebx
	push edi
	push esi
	
	mov esi,[ebp+12]
	mov edi,[ebp+16]
	
	test esi,esi
	jz _return0
	
	test edi,edi
	jz _return0

/*
------------------------------------------------------------------------
	Signal
------------------------------------------------------------------------
*/	
	mov ebx,esi
	mov ecx, edi
	and ebx,_SIG_MASK
	and ecx,_SIG_MASK
	xor ebx,ecx
/*
------------------------------------------------------------------------
	Expoent 
------------------------------------------------------------------------
*/	
	mov ecx, esi
	mov edx, edi

	and ecx,_EXP_MASK
	shr ecx, _MAT_SIZE
	sub ecx, _EXP_BIAS_MASK
	
	and edx, _EXP_MASK
	shr edx, _MAT_SIZE
	sub edx, _EXP_BIAS_MASK

	add cl,dl
	jo _return_false

	add ecx, _EXP_BIAS_MASK
	shl ecx, _MAT_SIZE
	or ebx,ecx
/*
------------------------------------------------------------------------
	Matisse Contemplar o Bit 'escondido' 
------------------------------------------------------------------------
*/	
	mov eax,esi
	and eax,_MAT_MASK
	or eax, _MAT_CORR_MASK

	and edi, _MAT_MASK
	or edi, _MAT_CORR_MASK

	mul edi
	/*
	--------------------------------------------------------------------
	Remontar o resultado de 48 bits para 24
	--------------------------------------------------------------------
	*/
	shr eax, 24
	shl edx,8


	or eax,edx
	shl eax,1
	and eax, _MAT_MASK
	or ebx,eax

	jmp _return1

_return0:
	xor eax,eax
_return1:
	mov ecx, [ebp+8]
	mov [ecx],ebx
	mov eax,1
	jmp _return

_return_false:
	xor eax,eax
	
_return:
	pop esi
	pop edi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
