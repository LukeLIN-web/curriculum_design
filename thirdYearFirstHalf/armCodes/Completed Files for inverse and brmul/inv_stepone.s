	area inv_stepone, code, readonly
	global inv_stepone
	import fmul
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	mov r13, r3;				; 给堆栈指针赋值
	mov r3, r1					; r3 存a[l]
	mov r7, #N  				; r7为控制循环上限
	mov r8, #N
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r4, r0, lsl #rr0		; r4为k
	mov r5, #0
	sub r5, r5, #offset			; r5为列控制参数j
loop
	add r5, r5, #offset			; j=j+1
	cmp r5, r7					; 控制循环
	bge stop					
	cmp r5, r4
	beq loop					; 若k==j, 则不执行操作进入下一轮循环
operation
	mov r1, r3 					; 令r1=a[l]
	mla r6, r4, r8, r5			; r6为k列的元素的下标  =u
	ldr r0, [r2, r6]			; r0=a[u], r1=a[l]
	stmia sp!,{r2-r12,r14}
	bl 	fmul					; a[u]=a[u]*a[l]
	ldmdb sp!,{r2-r12,r14}
	;mul r10, r9, r1				
	str r0, [r2, r6]			
	b loop
	
stop 
	mov r0, r4, lsr #rr0
	bx r14

	end