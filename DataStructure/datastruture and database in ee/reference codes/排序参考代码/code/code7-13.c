/* 数组排序 */
static void arraylist_sort_internal(ArrayListValue *listData,
                                    unsigned int listLength,
                                    ArrayListCompareFunc compare_func) {
	ArrayListValue pivot;
	ArrayListValue tmp;
	unsigned int i;
	unsigned int list1Length;
	unsigned int list2Length;

	/* 如果数据少于2个，则已经完成排序. */
	if (listLength <= 1)
		return;

	/* 将最后一个数据赋值给pivot. */
	pivot = listData[listLength-1];

	/* 将数组分为两组:
	 *
	 * List 1 包含小于pivot的数据.
	 * List 2 包含大于pivot的数据.
	 *
	 * 两个组建立之后，它们在数组中顺序排列.
     * 亦即：listData[list1Length-1]是组1中的最后一个数据，
     * listData[list1Length]是组2中的第一个数据.
	 */
	list1Length = 0;
	for (i=0; i<listLength-1; ++i)
		if (compare_func(listData[i], pivot) < 0) {

			/* 数据应在list 1中，故其处于错误的位置，将此数据与紧跟list 1最后一项的数据互换 */
			tmp = listData[i];
			listData[i] = listData[list1Length];
			listData[list1Length] = tmp;
			++list1Length;
		} else {
			/* 数据应在list 2中，故其已经位于正确的位置 */
		}

	/* list 2的长度可以计算得到 */
	list2Length = listLength - list1Length - 1;

	/* listData[0 ~ list1Length-1]现在包含了所有排序在pivot之前的数据，
     * listData[list1Length ~ listLength-2]包含了所有排序在pivot之后
     * 或者等于pivot的数据 */
	/* 通过互换pivot与list 2的第一个数据，将pivot移至正确的位置  */
	listData[listLength-1] = listData[list1Length];
	listData[list1Length] = pivot;

	/* 使用递归进行排序 */
	arraylist_sort_internal(listData, list1Length, compare_func);
	arraylist_sort_internal(&listData[list1Length + 1], list2Length,
	                        compare_func);
}

/* 执行递归排序 */
void arraylist_sort(ArrayList *arraylist, ArrayListCompareFunc compare_func) {
	arraylist_sort_internal(arraylist->data, arraylist->length,
	                        compare_func);
}
