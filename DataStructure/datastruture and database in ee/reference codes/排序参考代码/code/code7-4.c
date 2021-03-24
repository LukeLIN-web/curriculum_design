/* 一趟增量为dk的插入排序，dk为步长因子 */
void shell_insert(StaticTable *p, int dk, ArrayListCompareFunc compare_func){
	int i, j;
	for (i = dk + 1; i <= p->length - 1; i++)
		if (compare_func(p->data[i - dk], p->data[i])) {	/* 不相等时，需将r[i]插入有序表 */
			p->data[0] = p->data[i];	/* 为统一算法设置监测 */
			for (j = i - dk; j > 0 && compare_func(p->data[j], p->data[0]) == 1; j = j - dk)
				p->data[j + dk] = p->data[j];	/* 记录后移 */
			p->data[j + dk] = p->data[0];	/* 插入到正确的位置 */
		}
}

/* 按增量序列dlta[0,1...,t-1]对顺序表*p作希尔排序 */
void shell_sort(StaticTable *p, int dlta[], int t) {
	int k;
	for (k = 0; k < t; k++)
		shell_insert(p, dlta[k]);	/* 一趟增量为dlta[k]的插入排序 */ 
}