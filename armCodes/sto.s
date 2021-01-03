	area stoi, code, readonly
	global stoi
num equ 4
hed equ 10
start
    mov r3,#0           ;int n = 0 ;
    mov r7,#10
    mov r2,#0           ;iterator
loop1
    ldrb r5,[r0,r2]     ; *str char need use ldrb instead of ldr
    cmp r5,#0           ;
    bgt judge           ;if *str != '\0'
    b stop              ;
judge
    cmp r5,#48          ; 0 ascii = 48
    bge step
    b  stop             ;*str< 0 ,return n in r0
step 
    cmp r5,#58          ; 9 asccii = 57
    bge  stop           ; return n in r0
    sub r5,#48          ;
    mul r4,r3,r7          ;r3*10
    mov r3,r4
    add r3,r5           ; n = n*10 + (*str-'0')
    add r2,r2,#1      ;str ++
    b loop1           
stop
    mov r0,r3 ;
	bx lr
	end