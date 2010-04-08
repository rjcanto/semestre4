.intel_syntax noprefix

.data
v:		.long	-1,6,31,0,-15,22,2,-5
len:	.long	8
r:		.long	0

.text
.global main

main:
	lea esi, v

