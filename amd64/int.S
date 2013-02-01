	.intel_syntax noprefix
	.text
.globl Sum32
	.type	Sum32, @function
Sum32:
	/* Setup stack */
	push	rbp
	mov		rbp, rsp
	/* Setup local var for sum */
	push	rbx
	/* Reset return */
	xor		rax, rax
	/* Move rdx to that var */
	mov		ebx, edx
	/* Move rcx content to rdx */
	mov		edx, [rcx]
	/* Add the two integers */
	add		ebx, edx
	/* Set overflow if any */
	seto	al
	/* Return the result in the buffer */
	mov		[rcx], ebx
	/* End of the function */
	pop		rbx
	leave
	ret
	.size Sum32, .-Sum32

.globl Sub32
	.type	Sub32, @function
Sub32:
	/* Setup stack */
	push	rbp
	mov		rbp, rsp
	/* Setup local var for sub */
	push	rbx
	/* Reset return */
	xor		rax, rax
	/* Move rsi to that var */
	mov		ebx, edx
	/* Move rdi content to rsi */
	mov		edx, [rcx]
	/* Sub the two integers */
	sub		ebx, edx
	/* Set overflow if any */
	seto	al
	/* Check sign and jump */
	js		Sub32Ret
	/* Set negative sign */
	neg		ebx
Sub32Ret:
	/* Return the result in the buffer */
	mov		[rcx], ebx
	/* End of the function */
	pop		rbx
	leave
	ret
	.size Sub32, .-Sub32

.globl Div32
	.type	Div32, @function
Div32:
	/* Setup stack */
	push	rbp
	mov		rbp, rsp
	/* Setup registers */
	push	rdx
	/* Move dividend to eax */
	mov		eax, [rcx]
	/* Extend eax on 64bits */
	cltd
	/* Divide using ebx */
	idiv	ebx
	/* Move remainder in buffer */
	mov		[rcx], edx
	/* Return */
	pop		rdx
	leave
	ret
	.size Div32, .-Div32
