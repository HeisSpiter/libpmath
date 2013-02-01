	.intel_syntax noprefix
	.text
.globl Sum32
	.type	Sum32, @function
Sum32:
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
	.size Sum32, .-Sum32

.globl Sub32
	.type	Sub32, @function
Sub32:
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
	js		Sub32Ret
	/* Set negative sign */
	neg		ebx
Sub32Ret:
	/* Return the result in the buffer */
	mov		[ecx], ebx
	/* End of the function */
	pop		ebx
	leave
	ret
	.size Sub32, .-Sub32

.globl Div32
	.type	Div32, @function
Div32:
	/* Setup stack */
	push	ebp
	mov		ebp, esp
	/* Setup registers */
	push	edx
	/* Move dividend to eax */
	mov		eax, [ecx]
	/* Extend eax on 64bits */
	cltd
	/* Divide */
	idiv	ebx
	/* Move remainder in buffer */
	mov		[ecx], edx
	/* Return */
	pop		edx
	leave
	ret
	.size Div32, .-Div32
