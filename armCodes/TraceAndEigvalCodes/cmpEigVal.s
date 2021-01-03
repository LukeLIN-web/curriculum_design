    area cmpEigVal, code, readonly
	global cmpEigVal
num equ 4
rr1 equ 2
start
	mov r1, r1, lsl #rr1			; r1 = r1*4 从小到大排序, 
	mov r2, r2, lsl #rr1            ; r2 = r2*4
	ldr r5, [r0, r1]		; r5=Key[x]
	ldr r6, [r0, r2]		; r6=Key[y] ,LDR R0，[R1，R2] ；将存储器地址为R1+R2的字数据读入寄存器R0。
	cmp r5, r6				; 比较 Key[x] 和 Key[y]
	bge re1                 ;if key[x] > key[y] then return 1 else return 0 
    mov r0,#0				; set r0 = 0 as return value
    b stop
	b re1
re1
	mov r0,#1    		; 如果函数有返回值，那么返回值放在R0里。
stop
	bx lr
	end