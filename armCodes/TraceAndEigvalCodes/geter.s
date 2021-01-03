	area geter, code, readonly
	global geter
	import fadd
	import fmul
	import fsub
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start
    mov r0, r0, lsl #rr0	; p*4
    add r0,r1,r0            ;p*4 +q
    ldr r3,[r2,r0, lsl #2]          ;get 
    mov r0,r3   
stop 
	bx lr
	end
	
	
