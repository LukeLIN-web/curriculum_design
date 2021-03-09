/* 删除一个表中的特定结点，删除成功返回1，否则返回0 */
int slist_remove_entry(SListEntry **list, SListEntry *entry){
	SListEntry *rover;

	/* 如果链表或待删除结点为空，返回0 */
	if (*list == NULL || entry == NULL)
		return 0;

	/* 删除头结点需要不同操作 */
	if (*list == entry)

		/* 更新链表头指针，并断开头结点 */
		*list = entry->next;
    else {

		/* 搜索链表寻找前驱结点 */
		rover = *list;
		while (rover != NULL && rover->next != entry)
			rover = rover->next;
		if (rover == NULL)
			return 0;   /* 未找到 */
	    else

			/* rover->next现在指向entry, 所以rover是前驱结点，entry从链表中脱离 */
			rover->next = entry->next;
	}
	free(entry);    /* 释放结点内存 */
	return 1;   /* 操作成功 */
}