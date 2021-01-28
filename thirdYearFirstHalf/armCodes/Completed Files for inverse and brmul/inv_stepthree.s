	area inv_stepthree, code, readonly
	global inv_stepthree
	import fadd
	import fmul
	import fsub
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	mov r13, r3					; 给堆栈指针赋值
	mov r3, r1					; r3为a[l]
	mov r7, #N					; r7为控制循环上限
	mov r8, #N
	mov r4, r2					; r4存数组头地址
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r10, r0, lsl #rr0		; r10为k
	mov r5, #0
	sub r5, r5, #offset			; r5为行控制参数i
loop
	add r5, r5, #offset			; i=i+1
	cmp r5, r7					; 控制循环
	bge stop					
	cmp r5, r10
	beq loop					; 若k==i, 则不执行操作进入下一轮循环
operation
	mov r1, r3					; r1=-al
	mla r6, r5, r8, r10			; r6=i*n+k=u
	ldr r0, [r4, r6]			; r0= a[u]; r1=a[l]
	stmia sp!,{r2-r12,r14}
	bl 	fmul					; r0 = r0*r1 = a[u] * a[l]
	ldmdb sp!,{r2-r12,r14}
	;mul r10, r9, r11			; r10=a[u] * a[l]
	str r0, [r4, r6]			
	b loop
	
stop 
	mov r0, r10, lsr #rr0
	bx r14

	end
	
	
