    area fillApp, code, readonly
	global fillApp
num equ 4
rr1 equ 2
start
ini2
	ldr r5,[r3,#4]			; r5= p
	ldr r6,[r3,#8]			; r6= q
	mov r5, r5, lsl #rr1	; r5 = p*N
	add r6,r6,r5			; p*N+q
	ldr r7,[r1,r6]			; r1 save mat address , r7 = a[p*N+q]
	str r7,[r2]				;// float App[3] ={Apq,App,Aqq}; 	Apq = a[p*N+q]
	ldr r6,[r3,#4]			;r6= p
	add r6,r6,r5			; p*N+p
	ldr r7,[r1,r6]			;r1 save mat address , r7 = a[p*N+p]
	str r7,[r2,#4]			;// float App[3] ={Apq,App,Aqq}; 	App = a[p*N+p]
	ldr r6,[r3,#8]			; r6= q
	mov r6, r6, lsl #rr1	; r6 = q*N
	ldr r5,[r3,#8]			; r5= q
	add r6,r6,r5			;
	ldr r7,[r1,r6]			;r1 save mat address , r7 = a[q*N+]
	str r7,[r2,#8]				;// float App[3] ={Apq,App,Aqq}; 	Aqq = a[q*N+q]
stop
	bx lr
	end