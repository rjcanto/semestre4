.intel_syntax noprefix
.data
a:	.long	6
b:	.long	-3
r:	.long	0

.text
.global main

main:
	mov eax, a
	cmp eax,b
	jge done
	mov eax, b

done:
	mov r, eax
	ret
