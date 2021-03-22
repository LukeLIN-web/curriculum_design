ListEntry *lqueue_push(ListEntry **lqueue, ListValue data) {
	return list_append(lqueue, data);	//在链表尾插入数据
}