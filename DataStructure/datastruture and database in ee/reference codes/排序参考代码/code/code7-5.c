void bubble_sort(StaticTable *p, ArrayListCompareFunc compare_func){
	int i, j, n, noswap = 0;
	ArrayListValue swap;
	n = p->length;
	
	/* 每次循环初始化noswap，如果一次循环结束后仍然为TRUE，说明表完成排序 */ 
	for (i = 1; i <= n - 1 && !noswap; i++) {
		noswap = TRUE;
		for (j = n - 1; j >= i; j--)
		
			/* 如果相邻两个数不是按从小到大排列，交换两数 */ 
			if (compare_func(p->data[j - 1], p->data[j]) == 1) {
				swap = p->data[j - 1];
				p->data[j - 1] = p->data[j];
				p->data[j] = swap;
				noswap = FALSE;	/* 进入下一次循环 */ 
			}
	}
}