void distribute(StaticListNode &r, int i, ArrType &f, ArrType &e) {
	/* 静态链表list的r域中记录已按(keys[0],...,keys[i-1])有序 */
	/* 本算法按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录keys[i]相同 */
	/* f[0...RADIX-1]和e[0...RADIX-1]分别指向各子表中第一个和最后一个记录 */
	for(j = 0; j < Radix; j++)
		f[j] = 0;	/* 各子表初始化为空表 */ 
	for(p = r[0].next; p; p = r[p].next) {
		j = ord(r[p].keys[i]);	/* ord将记录中第i个关键字映射到[0...RADIX-1] */ 
		if(!f[j])
			f[j] = p;
		else
			r[e[j]].next = p;
		e[j] = p;	/* 将p所指的结点插入第j个子表中 */
	} 
}/* distribute */