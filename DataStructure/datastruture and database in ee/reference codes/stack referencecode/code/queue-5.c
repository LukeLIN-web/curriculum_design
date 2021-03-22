ListValue lqueue_peek(ListEntry *lqueue) {
	return list_nth_data(lqueue, 0);
}