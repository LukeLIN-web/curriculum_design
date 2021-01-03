    area initEigVec, code, readonly
	global initEigVec 
	import fadd
	import fmul
	import fsub
num equ 4
rr1 equ 2
start
	mov r5,#0                       ; r5 = i  , set init value as 1 
	mov r6,#0						; save 0 in r6 
loop
	str r6,[r0],#4			; a[i] = 0  
	add r5,r5,#1			;i ++
	cmp r5,r1    		 	;  if r5 >N    save N in r1 
	bge stop	 		 		; then set [i][i] = 1 
	b loop  			 	; else loop 
										; then set [i][i] = 1 
stop
	bx lr
	end