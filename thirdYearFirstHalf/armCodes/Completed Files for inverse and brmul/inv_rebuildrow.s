	area inv_rebuildrow, code, readonly
	global inv_rebuildrow
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
	cmp r0,r1
	beq stop1					; k==js[k],不做操作
	mov r7, #N  				; r7为控制循环上限
	mov r8, #N
	mov r7, r7, lsl #rr0		; float与int都占4个字节
	mov r4, r0, lsl #rr0		; r4为k
	mov r1, r1, lsl #rr0		; r1为js[k]
	mov r5, #0
	sub r5, r5, #offset			; r5为列控制参数j
loop
	add r5, r5, #offset			; j=j+1
	cmp r5, r7					; 控制循环
	bge stop					
operation
	mla r6, r4, r8, r5			; r6=k * n + j=u
	ldr r9, [r2, r6]			; r9=a[u]
	mla r10, r1, r8, r5			; r10= js[k] * n + j =v
	ldr r11, [r2, r10]			; r11=a[v]
	str r9, [r2, r10]
	str r11, [r2, r6]			;交换			
	b loop
	
stop 
	mov r0, r4, lsr #rr0
	bx lr
stop1
	bx lr

	end