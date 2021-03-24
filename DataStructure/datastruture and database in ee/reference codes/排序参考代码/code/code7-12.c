void radix_sort(StaticList &list) {
	/* list是采用静态链表表示的顺序法 */
	/* 对list作基数排序，使得list成为按关键字自小到大的有序静态链表，list.r[0]为头结点 */
	for(i = 0; i < list.recnum; i++)
		list.r[i].next = i + 1;
	list.r[recnum].next = 0;	/* 将list改造为静态链表 */
	for(i = 0; i < list.keynum; i++) {	/* 按最低位优先依次各关键字进行分配和收集 */
		distribute(list.r, i, f, e);	/* 第i趟分配 */
		collect(list.r, i, f, e);	/* 第i趟收集 */
	}
}/* radix_sort */