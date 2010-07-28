
.intel_syntax noprefix
.data

.text
.global x

x:
	push 	ebp
	mov		ebp, esp
	
	push	edi
	push	esi
	push	ebx
	
	push	[ebp+12]
