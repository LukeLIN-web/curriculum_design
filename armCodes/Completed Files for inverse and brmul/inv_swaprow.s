	area inv_swaprow, code, readonly
	global inv_swaprow
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	cmp r0, r1
	beq stop1					;; 若k==is[k]，则无需交换
	mov r7, #N  				; r7为控制循环上限
	mov r8, #N
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r4, r0, lsl #rr0		; r0为k
	mov r1, r1, lsl #rr0		; r1为is[k]
	mov r5, #0
	sub r5, r5, #offset			; r5为行位置控制参数j
loop
	add r5, r5, #offset			; j=j+1
	cmp r5, r7				; 控制外层循环
	bge stop
	mla r6, r4, r8, r5			; r6为k行的元素的下标  =u
	mla r9, r1, r8, r5			; r9为is[k]行的元素的下标  =v
	ldr r10, [r2, r6]			; r10=a[u]
	ldr r11, [r2, r9]			; r11=a[v]
	str r10, [r2, r9]			; 交换
	str r11, [r2, r6]			; 交换
	b loop
	
stop 
	mov r0, r4, lsr #rr0
	bx lr
stop1
	bx lr

	end