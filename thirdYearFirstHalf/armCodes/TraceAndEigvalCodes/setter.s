	area setter, code, readonly
	global setter
	import fadd
	import fmul
	import fsub
offset equ 4 	; int��floatռ�ֽ���
rr0 equ 2 		; offset = 2^(rr0)
N equ 3			; ����Ľ���
start
    mov r0, r0, lsl #rr0	; p*4
    add r0,r1,r0            ;p*4 +q
    str r2,[r3,r0, lsl #2]          ;set 
stop 
	bx lr
	end
	
	