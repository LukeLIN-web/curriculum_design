    area Trace, code, readonly
	global Trace
    import fadd
	import fmul
	import fsub
num equ 4
rr1 equ 2
start
    mov r13, r2                     ; store stack , 0,4,8
    mov r6,r1                        ; store mat address , 0,4,8
    mov r1,#0                   ;r1 = sum
    mov r5,#0                   ;extern void Trace(int i, float *mat,int *sp);
	ldr r0,[r6,r5,lsl #4]          ; ldr 
        ;需要保护r2~r12
	stmia sp!,{r2-r12,r14}
	bl fadd		;r0=r0+r1			
	ldmdb sp!,{r2-r12,r14}      ; save a[0]+sum in r0 
    add r5,r5,#4                ; r5 =4 
    ldr r1,[r6,r5,lsl #4]          ; ldr 
            ;需要保护r2~r12
	stmia sp!,{r2-r12,r14}
	bl fadd		;r0=r0+r1			
	ldmdb sp!,{r2-r12,r14}  ; save a[4]+sum in r0 
    add r5,r5,#4                ; r5 =4
    ldr r0,[r6,r5,lsl #4]          ; ldr  
            ;需要保护r2~r12
	stmia sp!,{r2-r12,r14}
	bl fadd		;r0=r0+r1			
	ldmdb sp!,{r2-r12,r14}  ; save a[8]+sum in r0 
     ;result store in r0;
stop
	bx lr
	end