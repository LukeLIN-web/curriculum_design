ListValue lqueue_pop(ListEntry **lqueue) {
	ListValue result = list_nth_data(*lqueue, 0);
	if(list_remove_entry(lqueue, *lqueue))	//移除链表头的数据
		return result;
	return LIST_NULL;
}