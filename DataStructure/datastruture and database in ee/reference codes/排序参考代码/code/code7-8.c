void merge_sort(StaticTable *p, ArrayListValue *rf, ArrayListCompareFunc compare_func) {
	//对*p表归并排序，*rf为与*p表等长的辅助数组
	ArrayListValue *q1, *q2, *swap;
	int i, len;
	q1 = rf;
	q2 = p->data;
	for(len = 1; len < p->length; len = 2*len) {	//从q2归并到q1
		for(i = 0; i + 2*len - 1 < p->length; i = i + 2*len)
			merge(q2, q1, i, i + len, i + 2*len - 1, compare_func);	//对等长的两个子表进行合并
		if(i + len - 1 < p->length)
			merge(q2, q1, i, i + len, p->length - 1, compare_func);	//对不等长的两个子表进行合并
		else if(i < p->length)
				while(i <= p->length) {
					q1[i] = q2[i];
					i++;
				}
		swap = q1;
		q1 = q2;
		q2 = swap;
	}
	if(q2 != p->data)	//若最终结果不在*p表中，则传入子表合并
		for(i = 0; i < p->length; i++)
			p->data[i] = q2[i];
}

/* 两个子表合并 */
/* 将*r表从第u项开始直到第t项的内容合并到*rf从u开始的后续项中，如果从u到v和v到t是不降的两组，那么合并后u到t的数据也是不降的 */
void merge(ArrayListValue *r, ArrayListValue *rf, int u, int v, int t, ArrayListCompareFunc compare_func) {
	int i, j, k;
	for(i = u, j = v, k = u; i < v && j <= t; k++) {
		if(compare_func(r[j], r[i]) == 1) {
			rf[k] = r[i];
			i++;
		}
		else {
			rf[k] = r[j];
			j++;
		}
	}
	if(i < v)
		for(; i < v; i++)
			rf[k++] = r[i];	//将*r从i到v-1的内容赋值给*rf从k到t
	if(j <= t)
		for(; j <= t; j++)
			rf[k++] = r[j];	//将*r从j到t的内容赋值给*rf从k到t
}