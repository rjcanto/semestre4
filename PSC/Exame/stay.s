.intel_syntax noprefix
.data

.text
.global stay

stay:
	push 	ebp
	mov		ebp,esp
	mov		eax,[ebp+8]
	lea		eax,[eax+eax*4]
	add		eax,eax
	add		eax,[ebp+12]
	pop ebp
	mov		eax,[stays + eax*4]
	ret
