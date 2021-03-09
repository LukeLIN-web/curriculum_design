/* 用链表迭代器获取链表中的下一个数据. */
SListValue slist_iter_next(SListIterator *iter){
	if (iter->current == NULL || iter->current != *iter->prev_next)

		/* 第一个结点还未读入，或已遍历至表尾，或当前遍历到的位置
		   的结点已删除，从prev_next得到下一个结点 */
		iter->current = *iter->prev_next;
	else {

		/* 当前遍历到的位置的结点存在，则遍历下一个结点 */
		iter->prev_next = &iter->current->next;
		iter->current = iter->current->next;
	}

	/* 判断当前遍历到的位置是否在表尾 */
	if (iter->current == NULL)
		return SLIST_NULL;
	else
		return iter->current->data;
}
