作业ppt5

Thumb指令和arm指令有什么不同?



Thumb功能为什么不能代替arm指令?

ppt6

n1.ARM-Thumb过程调用标准的目的是什么？

n2.内嵌汇编在使用物理寄存器要注意什么？



n3. C语言是与汇编语言程序是怎么互相调用的？

汇编调用C, **对于长度小于**8字节的结构型变量，可以通过一条****LDM/STM****指令来读****/****写整个变量，****对于结构型变量的数据成员，可以使用相应的****LDR/STR****指令来访问，但必须知道该数据成员相对于结构型变量开始地址的偏移量**



函数传参：
 4个以内的参数，直接存放在R0~R3 这4个寄存器里面。

 4个以后的参数放在堆栈里。

 如果函数有返回值，那么返回值放在R0里。



n4. 用汇编语言实现快速排序程序？



n5. ARM技术原理与应用(第2版)-第六章第3、7题



ppt 7 

作业1 , 6题.





作业第四题: 计算10的阶乘

```asmm
	AREA Fctrl,CODE,READONLY     声明dao代码段duFctrl  
	ENTRY         ; 标识程序入口  
	CODE32        ; 声明32 位ARM 指令 
START   
	MOV  R8 , #10    ;低位初始zhi化dao
	MOV  R9 , #0    ;高位初始化   
	SUB   R0,R8,#1    ;初始化计数器版 
Loop   
	MOV  R1 , R9    ;暂存高位值权   
	UMULL  R8 , R9 , R0 , R8  ;[R9:R8]=R0*R8   
	MLA  R9 , R1 , R0 , R9  ;R9=R1*R0+R9   
	SUBS  R0 , R0 , #1   计数器递减   
	BNE  Loop    ;计数器不为0继续循环 
Stop   
	B  Stop   
	END
```

作业第六题:

计算1到5的阶乘之和

```asmm
		AREA Fctrl,CODE,READONLY     ; declare Fctrl  
	ENTRY         ; 
	CODE32        ; declare 32 b ARM  
START   
	MOV  R6,  #0  ; save sum
	MOV  R7, #5   ;  R7  from 5 begin  
loop2   ;this is  FOR i-- 
	MOV  R8 , R7    ; init low bit , such as calculate 4!, R7 give 4 to R8
	MOV  R9 , #0    ; init high bit 
	SUB  R0,R8,#1    ; init R0 
Loop   ; for calculate i!
	MOV  R1 , R9    ;temp save high bit value    
	UMULL  R8 , R9 , R0 , R8  ;[R9:R8]=R0*R8   
	MLA  R9 , R1 , R0 , R9  ;   R9=R1*R0+R9   
	SUBS  R0 , R0 , #1  ;    R0 from 9 to 0 loop
	BNE  Loop    ;if not 0 continue loop ,dont' need cmp is ok . SUBS S will influence CPSR,  compare with zero  
	ADD  R6, R8,R6 ;  SUM =SUM + I! 
	SUBS R7, R7 ,#1 ; 
	BNE   loop2   
Stop   
	B  Stop   
	END
```

