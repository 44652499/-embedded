	.file	"charp.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$52, %esp
	movl	$1, -28(%ebp)
	movl	$2, -24(%ebp)
	movl	$3, -20(%ebp)
	movl	$4, -16(%ebp)
	movl	$56, -12(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$4, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$4, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$4, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	addl	$52, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20070925 (Red Hat 4.1.2-33)"
	.section	.note.GNU-stack,"",@progbits
