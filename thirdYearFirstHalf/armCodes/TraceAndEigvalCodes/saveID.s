    area saveId, code, readonly
	global saveId 
	import fadd
	import fmul
	import fsub
num equ 4
rr1 equ 2
start
ini2
	mov r7 ,#4              ; r7 = i 3 2 1 
loop2	
	sub r7,r7,#1            
    cmp r7,#0
    ble stop
    mov r5,r7               ;r5 = i 
    str r5,[r0,r7,lsl #2] 	;id[i]=i;
	mov r6,r7, lsl #2  		;  i*N+i  every loop  add N +1
	add r6,r6,r7     		;i*Eigen_N+i  , notice  don't  r7+N directly
    ldr r4,[r2,r6,lsl #2] 			; don't change r7 directly 
    str r4,[r1,r7,lsl #2] 			; key[i]=a[i*Eigen_N+i];
	b loop2  			 	; else loop2 
stop
	bx r14
	end