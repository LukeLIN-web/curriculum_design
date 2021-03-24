//这里需要传入函数compare_func，用来比较ArrayList中两个数据的大小关系，这里假设compare_func(value1, value2)满足value1>=value2时返回1，否则返回-1
void insert_sort(StaticTable *p, ArrayListCompareFunc compare_func){
	int i, j;
	for (i = 2; i <= p->length - 1; i++) {	/* p->length即为表长度n */

		/* 不相等时，需将data[i]插入有序表 */
		if (compare_func(p->data[i-1], p->data[i])) {
			p->data[0] = p->data[i];	/* 为统一算法设置监测 */
			for (j = i - 1; compare_func(p->data[j], p->data[0]) == 1; j--) {
				p->data[j + 1] = p->data[j];	/* 记录后移 */
				if(j == 0)
					break;
			}
			p->data[j + 1] = p->data[0];	/* 插入到正确的位置 */
		}
	}
}