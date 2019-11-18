	.file	"pass2.c"
	.text
	.comm	label_addr,10,8
	.globl	mnemonic
	.data
	.align 32
	.type	mnemonic, @object
	.size	mnemonic, 530
mnemonic:
	.string	""
	.zero	9
	.string	"ADD"
	.zero	6
	.string	"ADDF"
	.zero	5
	.string	"ADDR"
	.zero	5
	.string	"AND"
	.zero	6
	.string	"CLEAR"
	.zero	4
	.string	"COMP"
	.zero	5
	.string	"COMPF"
	.zero	4
	.string	"COMPR"
	.zero	4
	.string	"DIV"
	.zero	6
	.string	"DIVF"
	.zero	5
	.string	"DIVR"
	.zero	5
	.string	"J"
	.zero	8
	.string	"JEQ"
	.zero	6
	.string	"JGT"
	.zero	6
	.string	"JLT"
	.zero	6
	.string	"JSUB"
	.zero	5
	.string	"LDA"
	.zero	6
	.string	"LDB"
	.zero	6
	.string	"LDCH"
	.zero	5
	.string	"LDF"
	.zero	6
	.string	"LDL"
	.zero	6
	.string	"LDS"
	.zero	6
	.string	"LDT"
	.zero	6
	.string	"LDX"
	.zero	6
	.string	"LPS"
	.zero	6
	.string	"MUL"
	.zero	6
	.string	"MULF"
	.zero	5
	.string	"MULR"
	.zero	5
	.string	"OR"
	.zero	7
	.string	"RD"
	.zero	7
	.string	"RMO"
	.zero	6
	.string	"RSUB"
	.zero	5
	.string	"SHIFTL"
	.zero	3
	.string	"SHIFTR"
	.zero	3
	.string	"STA"
	.zero	6
	.string	"STB"
	.zero	6
	.string	"STCH"
	.zero	5
	.string	"STF"
	.zero	6
	.string	"STL"
	.zero	6
	.string	"STS"
	.zero	6
	.string	"STSW"
	.zero	5
	.string	"STT"
	.zero	6
	.string	"STX"
	.zero	6
	.string	"SUB"
	.zero	6
	.string	"SUBF"
	.zero	5
	.string	"SUBR"
	.zero	5
	.string	"TD"
	.zero	7
	.string	"TIX"
	.zero	6
	.string	"TIXR"
	.zero	5
	.string	"WD"
	.zero	7
	.string	"FIX"
	.zero	6
	.string	"FLOAT"
	.zero	4
	.globl	hex
	.section	.rodata
	.align 32
	.type	hex, @object
	.size	hex, 159
hex:
	.string	""
	.zero	2
	.string	"18"
	.string	"58"
	.string	"90"
	.string	"40"
	.string	"B4"
	.string	"28"
	.string	"88"
	.string	"A0"
	.string	"24"
	.string	"64"
	.string	"9C"
	.string	"3C"
	.string	"30"
	.string	"34"
	.string	"38"
	.string	"48"
	.string	"00"
	.string	"68"
	.string	"50"
	.string	"70"
	.string	"08"
	.string	"6C"
	.string	"74"
	.string	"04"
	.string	"D0"
	.string	"20"
	.string	"60"
	.string	"98"
	.string	"44"
	.string	"D8"
	.string	"AC"
	.string	"4C"
	.string	"A4"
	.string	"A8"
	.string	"0C"
	.string	"78"
	.string	"54"
	.string	"80"
	.string	"14"
	.string	"7C"
	.string	"E8"
	.string	"84"
	.string	"10"
	.string	"1C"
	.string	"5C"
	.string	"94"
	.string	"E0"
	.string	"2C"
	.string	"B8"
	.string	"DC"
	.string	"C4"
	.string	"C0"
	.text
	.globl	is_opcode
	.type	is_opcode, @function
is_opcode:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L5:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	mnemonic(%rip), %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L3
	movl	-4(%rbp), %eax
	jmp	.L4
.L3:
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	$52, %eax
	jbe	.L5
	movl	$0, %eax
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	is_opcode, .-is_opcode
	.globl	find_length
	.type	find_length, @function
find_length:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$99, %al
	jne	.L7
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	subl	$3, %eax
	jmp	.L8
.L7:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	subq	$3, %rax
	shrq	%rax
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	find_length, .-find_length
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"symtab.txt"
.LC2:
	.string	"%s%s"
.LC3:
	.string	"%c"
.LC4:
	.string	"%x"
	.text
	.globl	find_sym
	.type	find_sym, @function
find_sym:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -40(%rbp)
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	nop
.L10:
	movl	-48(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -48(%rbp)
	movslq	%eax, %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L10
	movl	-48(%rbp), %eax
	cltq
	leaq	-3(%rax), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L12
	movl	$1, -44(%rbp)
	movl	-48(%rbp), %eax
	cltq
	leaq	-3(%rax), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	jmp	.L12
.L15:
	leaq	-18(%rbp), %rcx
	leaq	-28(%rbp), %rdx
	movq	-40(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	leaq	-28(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L12
	cmpl	$0, -44(%rbp)
	je	.L13
	movzbl	-18(%rbp), %eax
	movsbl	%al, %edx
	leaq	-30(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	leaq	-30(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	xorl	$8, %eax
	movl	%eax, %edx
	leaq	-30(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	movzbl	-30(%rbp), %eax
	movb	%al, -18(%rbp)
.L13:
	leaq	-18(%rbp), %rax
	movq	%rax, %rsi
	leaq	label_addr(%rip), %rdi
	call	strcpy@PLT
	movl	$1, %eax
	jmp	.L16
.L12:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	feof@PLT
	testl	%eax, %eax
	je	.L15
	movl	$0, %eax
.L16:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	find_sym, .-find_sym
	.section	.rodata
.LC5:
	.string	"temp.txt"
.LC6:
	.string	"a"
.LC7:
	.string	"obj.txt"
.LC8:
	.string	"list.txt"
.LC9:
	.string	"len.txt"
.LC10:
	.string	"%s"
.LC11:
	.string	"%s%s%s"
.LC12:
	.string	"START"
.LC13:
	.string	"-"
.LC14:
	.string	"%s %s"
.LC15:
	.string	"H^%s^%06x^%s"
.LC16:
	.string	"\nT^%06x"
	.align 8
.LC17:
	.string	"Error [undefined symbol] on line %d \n"
.LC18:
	.string	"WORD"
.LC19:
	.string	"%06x"
.LC20:
	.string	"BYTE"
.LC21:
	.string	"RESW"
.LC22:
	.string	"RESB"
.LC23:
	.string	"^%s"
.LC24:
	.string	"END"
.LC25:
	.string	"\nT^00%s"
.LC26:
	.string	"\nE^%06x"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$757935405, -94(%rbp)
	movw	$11565, -90(%rbp)
	movb	$0, -88(%rbp)
	movl	$0, -156(%rbp)
	movl	$0, -152(%rbp)
	movl	$0, -144(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	.LC5(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -136(%rbp)
	leaq	.LC6(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -128(%rbp)
	leaq	.LC6(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -120(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -112(%rbp)
	leaq	-57(%rbp), %rdx
	movq	-112(%rbp), %rax
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	leaq	-67(%rbp), %rsi
	leaq	-77(%rbp), %rcx
	leaq	-87(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rsi, %r8
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	addl	$1, -144(%rbp)
	leaq	-77(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L19
	leaq	-87(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L20
	leaq	-87(%rbp), %rdx
	leaq	-94(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
.L20:
	leaq	-67(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -156(%rbp)
	leaq	-67(%rbp), %rcx
	leaq	-77(%rbp), %rdx
	movq	-120(%rbp), %rax
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	leaq	-67(%rbp), %rsi
	leaq	-77(%rbp), %rcx
	leaq	-87(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rsi, %r8
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	addl	$1, -144(%rbp)
.L19:
	leaq	-57(%rbp), %rsi
	movl	-156(%rbp), %ecx
	leaq	-94(%rbp), %rdx
	movq	-128(%rbp), %rax
	movq	%rsi, %r8
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	-156(%rbp), %edx
	movq	-128(%rbp), %rax
	leaq	.LC16(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L21
.L43:
	nop
.L22:
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	is_opcode
	movl	%eax, -140(%rbp)
	cmpl	$0, -140(%rbp)
	je	.L23
	movb	$0, -47(%rbp)
	addl	$3, -152(%rbp)
	leaq	-67(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L24
	leaq	-67(%rbp), %rax
	movq	%rax, %rdi
	call	find_sym
	testl	%eax, %eax
	jne	.L26
	movl	$808464432, label_addr(%rip)
	movb	$0, 4+label_addr(%rip)
	movl	-144(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC17(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L26
.L24:
	movl	$808464432, label_addr(%rip)
	movb	$0, 4+label_addr(%rip)
.L26:
	movl	-140(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	hex(%rip), %rdx
	addq	%rax, %rdx
	leaq	-47(%rbp), %rax
	leaq	label_addr(%rip), %rcx
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	jmp	.L27
.L23:
	leaq	-77(%rbp), %rax
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L28
	addl	$3, -152(%rbp)
	movb	$0, -47(%rbp)
	leaq	-67(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, %edx
	leaq	-47(%rbp), %rax
	leaq	.LC19(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	jmp	.L27
.L28:
	leaq	-77(%rbp), %rax
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L27
	leaq	-67(%rbp), %rax
	movq	%rax, %rdi
	call	find_length
	addl	%eax, -152(%rbp)
	movb	$0, -47(%rbp)
	leaq	-67(%rbp), %rax
	movq	%rax, -104(%rbp)
	addq	$2, -104(%rbp)
	movl	$0, -148(%rbp)
	nop
.L29:
	movl	-148(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -148(%rbp)
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L29
	movl	-148(%rbp), %eax
	cltq
	leaq	-2(%rax), %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movzbl	-67(%rbp), %eax
	cmpb	$120, %al
	jne	.L30
	movq	-104(%rbp), %rdx
	leaq	-47(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	jmp	.L27
.L30:
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -148(%rbp)
	jmp	.L31
.L32:
	movl	-148(%rbp), %eax
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	leaq	-32(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	leaq	-32(%rbp), %rdx
	leaq	-47(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat@PLT
	addl	$1, -148(%rbp)
.L31:
	movl	-148(%rbp), %eax
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L32
.L27:
	cmpl	$30, -152(%rbp)
	jg	.L36
	leaq	-77(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC21(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L36
	leaq	-77(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC22(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L36
	leaq	-47(%rbp), %rdx
	movq	-128(%rbp), %rax
	leaq	.LC23(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movb	$0, -47(%rbp)
	leaq	-77(%rbp), %rax
	leaq	.LC24(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L34
	jmp	.L42
.L37:
	leaq	-67(%rbp), %rsi
	leaq	-77(%rbp), %rcx
	leaq	-87(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rsi, %r8
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	addl	$1, -144(%rbp)
.L36:
	leaq	-77(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC21(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L37
	leaq	-77(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC22(%rip), %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L37
	leaq	-87(%rbp), %rdx
	movq	-128(%rbp), %rax
	leaq	.LC25(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	cmpl	$30, -152(%rbp)
	jle	.L22
	movl	$0, -152(%rbp)
	jmp	.L22
.L34:
	movl	-156(%rbp), %edx
	movq	-128(%rbp), %rax
	leaq	.LC26(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L39
.L42:
	leaq	-67(%rbp), %rsi
	leaq	-77(%rbp), %rcx
	leaq	-87(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rsi, %r8
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	addl	$1, -144(%rbp)
.L21:
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	feof@PLT
	testl	%eax, %eax
	je	.L43
.L39:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L41
	call	__stack_chk_fail@PLT
.L41:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
