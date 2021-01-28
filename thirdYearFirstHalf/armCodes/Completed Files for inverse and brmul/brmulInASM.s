	area brmulInASM, code, readonly
	global brmulInASM
	import fadd
	import fmul
	import fsub
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	mov r13, r3					; 设置栈指针
	mov r10, r0					; r10 存a数组的首地址
	mov r11, r1					; r11 存b数组的首地址
	mov r7, #N  				; r7为控制循环上限
	mov r8, #N
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r5, #0
	sub r5, r5, #offset			; r5为行控制参数i
loop1
	add r5, r5, #offset			; i=i+1
	cmp r5, r7					; 控制循环
	bge stop					
	mov r6, #0
	sub r6, r6, #offset			; r6为列控制参数j
loop2
	add r6, r6, #offset
	cmp r6, r7
	bge loop1
	mov r9, #0
	sub r9, r9, #offset			; r9为控制参数l
	mov r12, #0
	mla r3, r5, r8, r6			; r3=i*n+j=u
	str r12, [r2, r3]			; c[u]=0
loop3
	add r9, r9, #offset
	cmp r9, r7
	bge loop2
operation
	mla r4, r5, r8, r9			; r4=i * n + l
	ldr r0, [r10, r4]			; r0= a[i * n + l]
	mla r4, r9, r8, r6			; r4=l * n + j
	ldr r1, [r11, r4]			; r1= b[i * n + l]
	;保护r2-r12,r14
	stmia sp!,{r2-r12,r14}
	bl 	fmul					; r0 = a[i * n + l]* b[i * n + l]
	ldmdb sp!,{r2-r12,r14}
	ldr r1, [r2, r3]			; r1 = c[u]
	;
	stmia sp!,{r2-r12,r14}
	bl 	fadd					; r0 = c[u]+a[i * n + l]* b[i * n + l]
	ldmdb sp!,{r2-r12,r14}
	str r0, [r2, r3]
	b loop3
	
stop 
	bx r14

	end