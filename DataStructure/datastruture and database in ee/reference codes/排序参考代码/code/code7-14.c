/* 用于内部快速排序的函数，返回排序后的尾结点 */
static SListEntry *slist_sort_internal(SListEntry **list,
                                       SListCompareFunc compare_func) {
	SListEntry *pivot;
	SListEntry *rover;
	SListEntry *lessList, *moreList;
	SListEntry *lessListEnd, *moreListEnd;

	/* 如果数据少于2个，则已经完成排序 */
	if (*list == NULL || (*list)->next == NULL)
		return *list;

	/* pivot指向头结点 */
	pivot = *list;

	/* 从第二个结点开始遍历链表。根据每个结点与头结点比较的结果，将
	 * 结点归入less list和more list两个子链表中 */
	lessList = NULL;
	moreList = NULL;
	rover = (*list)->next;
	while (rover != NULL) {
		SListEntry *next = rover->next;
		if (compare_func(rover->data, pivot->data) < 0) {

			/* 把这个结点放入less list中 */
			rover->next = lessList;
			lessList = rover;
		} else {

			/* 把这个结点放入more list中 */
			rover->next = moreList;
			moreList = rover;
		}
		rover = next;
	}

	/* 对子链表递归排序 */
	lessListEnd = slist_sort_internal(&lessList, compare_func);
	moreListEnd = slist_sort_internal(&moreList, compare_func);

	/* 创新以less less为开始部分新链表 */
	*list = lessList;

	/* 把pivot结点插入less list的尾部。若less list为空，以povit为表头 */
	if (lessList == NULL)
		*list = pivot;
	else 
		lessListEnd->next = pivot;

	/* 在pivot结点后插入more list */
	pivot->next = moreList;

	/* 返回链表的尾节点 */
	if (moreList == NULL)
		return pivot;
	else
		return moreListEnd;
}

void slist_sort(SListEntry **list, SListCompareFunc compare_func) {
	slist_sort_internal(list, compare_func);
}
