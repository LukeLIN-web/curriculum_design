    area initEigVec2, code, readonly
	global initEigVec2 
	import fadd
	import fmul
	import fsub
num equ 4
rr1 equ 2
start
ini2
	mov r13, r1;			; 给堆栈指针赋值 
	mov r1,#0x3f800000		; r1 = float 1.0
	mov r2,r0				;save the address of EigVec
	mov r7 ,#1  			;r7 = 1,2,3 
loop2	
	mov r1,#0x3f800000		; r1 = float 1.0
	add r6,r6,#num  		;  i*N+i  every loop  add N +1
	add r6,r6,#1     		; r6 save the address of element
	mov r5,r6   			; r1 = i*N+i
	ldr r0,[r2,r5,lsl #2] 			;
	stmia sp!,{r2-r12,r14}
	bl fadd		;r0=r0+r1			
	ldmdb sp!,{r2-r12,r14}
	str r0,[r2,r5,lsl #2] 			; save back  
	add r7,r7,#1			;
	cmp r7,#4    		 	;  if r7 <4   , save N in r1 
	bge stop	 		 	; then set [i][i] = 1 
	b loop2  			 	; else loop2 
	
stop
	bx r14
	end