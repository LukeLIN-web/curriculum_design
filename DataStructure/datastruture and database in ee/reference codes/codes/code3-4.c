/* 返回满足某个特定值的结点在表list中第一次出现的指针，如果没找到data返回NULL */
SListEntry *slist_find_data(SListEntry *list,
                            SListEqualFunc callback,
                            SListValue data) {
	SListEntry *rover;

	/* 遍历链表，直到找到存有指定数据的结点 */
	for (rover = list; rover != NULL; rover = rover->next) {
		if (callback(rover->data, data) != 0) {
			return rover;
		}
	}

	/* 特定值未找到 */
	return NULL;
}