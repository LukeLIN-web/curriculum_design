    area sum, code, readonly
	global sum
start
	
	mov r1,r0
	mov r5,r2 
	mov r6,r2
	mov r7,r2 ;128bits in r5,r6,r7,r8
	mov r8,r2 
	mov r2,r0
	mov r3,r0  ;128bits  in r0,r1,r2,r3
	mov r4,#0
	mov r9,#0
	adds r0,r0,r5
	adc r1,r1,r6 ; {r1= 1 ,r0 = r0+r2, r1 = r1+r3+ C}  could command adc  change the C in CPSR?
	adc r2,r2,r7 
	adc r3,r3,r8 
	adc r4,r4,r9
stop
	mov pc, lr
	end