	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, -20(%rbp)
	cmpl	$2, -8(%rbp)
	je	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$-1, -4(%rbp)
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	jmp	LBB0_6
LBB0_2:
	xorl	%esi, %esi
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	movb	$0, %al
	callq	_open
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	jne	LBB0_4
## BB#3:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB0_5
LBB0_4:
	leaq	L_.str.2(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
LBB0_5:
	movl	$0, -4(%rbp)
LBB0_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Insufficient arguements\n\n"

L_.str.1:                               ## @.str.1
	.asciz	"Unable to open File\n\n"

L_.str.2:                               ## @.str.2
	.asciz	"File is successfully opened with file descriptor %d \n"


.subsections_via_symbols
