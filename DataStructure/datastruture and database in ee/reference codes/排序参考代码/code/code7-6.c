/* 递归形式的快速排列 */
/* 对顺序表tbl中的子序列tbl->[low...high]作快速排列 */ 
void quick_sort(StaticTable *tbl, int low, int high, ArrayListCompareFunc compare_func) {
	int pivotloc;
	if(low < high) {
		pivotloc = arraylist_partition(tbl, low, high, compare_func);	/* 将表一分为二 */
		quick_sort(tbl, low, pivotloc - 1, compare_func);	/* 对低子表递归排序 */
		quick_sort(tbl, pivotloc + 1, high, compare_func);	/* 对高子表递归排序 */
	}
}

/* 一趟快速排序 */
/* 交换顺序表tbl中子表tbl->data[low...high]的记录，使支点记录到位，并返回其所在位置，此时在它之前（后）的记录均不大（小）于它 */
int arraylist_partition(ArrayList *arraylist, int low, int high, ArrayListCompareFunc compare_func) {
    ArrayListValue pivotkey;	/* 记录支点数据的变量 */
    ArrayListValue temp;
    pivotkey = arraylist->data[low];	/* 取支点记录关键字 */
    while(low < high) {	/* 从表的两端交替地向中间扫描 */
        while(low < high && compare_func(arraylist->data[high], pivotkey) >= 0)
            high--;
        temp = arraylist->data[low];
        arraylist->data[low] = arraylist->data[high];
		arraylist->data[high] = temp;	/* 将比支点记录小的交换到低端 */
        while(low < high && compare_func(pivotkey, arraylist->data[low]) >= 0)
            low++;
        temp = arraylist->data[high];
        arraylist->data[high] = arraylist->data[low];
		arraylist->data[low] = temp;	/* 将比支点记录大的交换到高端 */
    }
    return low; /* 返回支点记录所在位置 */
}