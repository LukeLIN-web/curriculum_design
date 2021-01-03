    area FindMax, code, readonly
	global FindMax
num equ 4
rr1 equ 2
start
;max in r0, a in r1, n=3 in r2

init
    mov r6,r2               ;  r6 set init value as  n = 3  ,r6 = j ,in loop
	sub r5,r2,#1 			;  r5 set init value as  n-1 = 2  ,r5 = i ,out loop
loop1
    sub r5,r5,#1            ;r5--
    cmp r5,#0               ; if r5<= 0
    bls stop                ; if r5<= 0 then stop loop 
init2
    add r6,r2,#1               ;r6 set init value as  n+1 = 4  ,r6 = j ,in loop
loop2
    sub r6,r6,#1            ; first r6--
    cmp r6,r5               ; if r6<= r5
    bls loop1               ; if r6<= r5 then stop loop 
    ;  else if fabs(a[i*N+j]) > mx_val 
    mov r7, r5, lsl #rr1	; r1 logical shift left 2 bits; r1 = r1*4 
    add r7,r7,r6            ;r7  =i*N+j
    mov r7, r7, lsl #rr1    ;[i*N+j]
    ldr r8,[r1,r7]          ; if r7 frist is 1 ;    only 16bits imm in  once send 
    cmp r8, #0 
    bgt con                 ; r8 >= 0 continue  else r8 = -r8
	mov r4,0				;save 0 in r4 as tmp
    sub r8,r4,r8             ;fabs(a[i*N+j] =|r8| = 0-r8  
con
    ldr r3,[r0]             ;max save [mx_val, rowid, col_id] 
    cmp r8, r3              ; if (fabs(a[i*N+j]) > mx_val)  
    bge save                ;save r8;
    b loop2                 ;else j--
save 
    str r8,[r0]			    ;save the mx_val = fabs(a[i*N+j])
    str r5,[r0,#4]			;row_id = i
    str r6,[r0,#8]			;col_id = j;
    b loop2
stop
	bx lr
	end