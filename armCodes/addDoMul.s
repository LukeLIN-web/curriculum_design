    area addDoMul, code, readonly
	global addDoMul
start
	mov r5,#0  			; r5 =sum 	
loop1
	TST r1,#0x01 
	beq con				; if lowest bit is 0, eq is 1 , continue without add r0 into r5
	add r5,r5,r0		; 7*1
	mov r0, r0, lsl #1 	;	 r0*2
	mov r1,r1,lsr #1 	; 
	cmp r1,#0
	bgt loop1
	b stop 
con
	mov r0, r0, lsl #1 	; r0 still need *2 , 7*（4+2+1) is 7*4 + 7*2 + 7*1
	mov r1,r1,lsr #1 	; 
	b loop1 
stop
	mov r0,r5 
	bx lr
	end