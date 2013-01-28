	.intel_syntax noprefix
	.text
.globl Sum
	.type	Sum, @function
Sum:
	/* Setup stack */
	push	ebp
	mov		ebp, esp
	/* Setup local var for sum */
	push	ebx
	/* Reset return */
	xor		eax, eax
	/* Move edx to that var */
	mov		ebx, edx
	/* Move ecx content to edx */
	mov		edx, [ecx]
	/* Add the two integers */
	add		ebx, edx
	/* Set overflow if any */
	seto	al
	/* Return the result in the buffer */
	mov		[ecx], ebx
	/* End of the function */
	pop		ebx
	leave
	ret
	.size Sum, .-Sum

.globl Sub
	.type	Sub, @function
Sub:
	/* Setup stack */
	push	ebp
	mov		ebp, esp
	/* Setup local var for sub */
	push	ebx
	/* Reset return */
	xor		eax, eax
	/* Move edx to that var */
	mov		ebx, edx
	/* Move ecx content to edx */
	mov		edx, [ecx]
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
	mov		[ecx], ebx
	/* End of the function */
	pop		ebx
	leave
	ret
	.size Sub, .-Sub

.globl Div
	.type	Div, @function
Div:
	/* Setup stack */
	push	ebp
	mov		ebp, esp
	/* Setup registers */
	push	edx
	/* Move dividend to eax */
	mov		eax, [ecx]
	/* Zero edx (unused) */
	xor		edx, edx
	/* Divide */
	idiv	ebx
	/* Move remainder in buffer */
	mov		[ecx], edx
	/* Return */
	pop		edx
	leave
	ret
	.size Div, .-Div