	area sort, code, readonly
	global sort
num equ 4
rr1 equ 2
start
init
    mov r6,#1              ;   r6 set init value as  1  ,r6 = j ,in loop
	mov r5,#20 				;  r5 set init value as 20  ,r5 = i ,out loop
loop1
    sub r5,r5,#1          ;r5--
    cmp r5,#0               ; if r5<= 0
    bls stop                ; if r5<= 0 then stop loop 
init2
    mov r6,#1             ;r6 =1  ,r6 = j ,in loop
loop2
	ldr r3,[r0,r6, lsl #2]			;number[j] 
	add r6,r6,#-1
	ldr r4,[r0,r6, lsl #2]			;number[j-1] 
	add r6,r6,#1
	cmp r4,r3				;
	bge	swap				;number[j-1] >=number[j]
	b con 				;
swap
	str r4,[r0, r6, lsl #2] 	 ;str number[j-1]  
	sub r6,r6,#1
	str r3,[r0, r6, lsl #2] 	;str number[j]   
	add r6,r6,#1 
con
	add r6,r6,#1
	cmp r6,r5
	ble loop2 
	b loop1
stop
	bx lr
	end