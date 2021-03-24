void collect(StaticListNode &r, int i, ArrType f, ArrType e) {
	/* 本算法按keys[i]自小至大地将f[0...RADIX-1]所指各子表依次链接成一个链表 */
	/* e[0...RADIX]为各子表的尾指针 */
	for (j = 0; !f[j]; j = succ(j));	/* 找第一个非空子表，succ为求后继函数 */
	r[0].next = f[j];	/* r[0].next指向第一个非空子表中第一个结点 */ 
	t = e[j];
	while (j < RADIX) {
		for (j = succ(j); j < RADIX && !f[j];j = succ(j));	/* 找下一个非空子集 */
		
		/* 链接两个非空子表 */ 
		if (f[j]) {
			r[t].next = f[j];
			t = e[j];
		}
	}
	r[t].next = 0;	/* t指向最后一个非空子表中的最后一个结点 */ 
}/* collect */