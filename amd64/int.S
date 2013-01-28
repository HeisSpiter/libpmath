	.intel_syntax noprefix
	.text
.globl Sum
	.type	Sum, @function
Sum:
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
	.size Sum, .-Sum

.globl Sub
	.type	Sub, @function
Sub:
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
	js		SubRet
	/* Set negative sign */
	neg		ebx
SubRet:
	/* Return the result in the buffer */
	mov		[rcx], ebx
	/* End of the function */
	pop		rbx
	leave
	ret
	.size Sub, .-Sub

.globl Div
	.type	Div, @function
Div:
	/* Setup stack */
	push	rbp
	mov		rbp, rsp
	/* Setup registers */
	push	rdx
	/* Move dividend to eax */
	mov		eax, [rcx]
	/* Zero rdx (unused) */
	xor		rdx, rdx
	/* Divide using ebx */
	idiv	ebx
	/* Move remainder in buffer */
	mov		[rcx], edx
	/* Return */
	pop		rdx
	leave
	ret
	.size Div, .-Div
