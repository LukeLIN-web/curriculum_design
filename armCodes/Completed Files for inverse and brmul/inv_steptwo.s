	area inv_steptwo, code, readonly
	global inv_steptwo
	import fadd
	import fmul
	import fsub
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	mov r13, r2					; 给栈指针赋值
	mov r3, r1					; r3存数组首地址
	mov r7, #N  				; r7为控制循环上限
	mov r8, #N
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r4, r0, lsl #rr0		; r4为k
	mov r5, #0
	sub r5, r5, #offset			; r5为行控制参数i
loop
	add r5, r5, #offset			; i=i+1
	cmp r5, r7					; 控制循环
	bge stop					
	cmp r5, r4
	beq loop					; 若k==i, 则不执行操作进入下一轮循环
	mov r6, #0
	sub r6, r6, #offset			; r6为列控制参数j
loop0
	add r6, r6, #offset
	cmp r6, r7
	bge loop
	cmp r6, r4					; 若k==j，则不进行操作进入下一轮循环
	beq loop0
operation
	mla r9, r5, r8, r4			; r9=i*n+k
	ldr r0, [r3, r9]			; r0= a[i*n+k]
	mla r9, r4, r8, r6			; r9=k*n+j
	ldr r1, [r3, r9]			; r1=a[k*n+j]
	;保护r2-r12,r14
	stmia sp!,{r2-r12,r14}
	bl 	fmul					; r0 = a[i*n+k] * a[k*n+j]
	ldmdb sp!,{r2-r12,r14}
	mov r1, r0					; r1 = a[i*n+k] * a[k*n+j]
	mla r9, r5, r8, r6			; r9=i*n+j=u
	ldr r0, [r3, r9]			; r0=a[u]
	;保护r2-r12,r14
	stmia sp!,{r2-r12,r14}
	bl 	fsub					; r0 = a[u]-a[i * n + k] * a[k * n + j]
	ldmdb sp!,{r2-r12,r14}
	str r0, [r3, r9]			
	b loop0
	
stop 
	mov r0, r4, lsr #rr0
	bx r14

	end