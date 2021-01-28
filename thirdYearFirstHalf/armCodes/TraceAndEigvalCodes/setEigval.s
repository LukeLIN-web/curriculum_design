	area setEigval ,code, readonly
	global setEigval
	import fadd
	import fmul
	import fsub
offset equ 4 	; int和float占字节数
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; 矩阵的阶数
start	
    ldr r4,[r1,r0, lsl #2] ; r4 = id[i] setEigval(i,id,EigVal);
    mov r5,r4, lsl #2       ;r5  id[i]*Eigen_N
    add r4,r5,r4            ;r4  = id[i]*Eigen_N+id[i]
    ldr r3,[r3,r4, lsl #2]  ;a[id[i]*Eigen_N+id[i] ] 
    str r3,[r2,r0, lsl #2]          ;set 
stop 
	bx lr
	end
	
	