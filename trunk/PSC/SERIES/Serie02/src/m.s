	.file	"mulff.c"
	.text
.globl mulffp
	.type	mulffp, @function
mulffp:
	pushl	%ebp
	movl	%esp, %ebp
	flds	12(%ebp)
	fmuls	16(%ebp)
	movl	8(%ebp), %eax
	fstps	(%eax)
	movl	$1, %eax
	popl	%ebp
	ret
	.size	mulffp, .-mulffp
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$28, %esp
	movl	$0, -4(%ebp)
	movl	$0x40200000, %eax
	movl	%eax, 8(%esp)
	movl	$0x40200000, %eax
	movl	%eax, 4(%esp)
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	mulffp
	movl	$1, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
