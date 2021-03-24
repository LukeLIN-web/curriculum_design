void select_sort(StaticTable *s, ArrayListCompareFunc compare_func) {
	int i, j, t;
	ArrayListValue swap;
	
	/* 作length - 1趟选取 */
	for(i = 1; i < s->length; i++) {

		/* 在i开始的length - i + 1个记录中选关键码最小的记录 */
		for (j = i + 1, t = i; j <= s->length - 1; j++)
			if(compare_func(s->data[t], s->data[j]) == 1)
				t = j;	/* t中存放关键码最小记录的下标 */
		
		/* 关键码最小的记录与第i个记录交换 */
		swap = s->data[t];
		s->data[t] = s->data[i];
		s->data[i] = swap;
	}
}