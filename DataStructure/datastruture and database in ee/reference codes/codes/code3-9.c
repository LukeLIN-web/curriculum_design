void slist_free(SListEntry *list){
	SListEntry *entry,*next;

	/* 遍历所有结点，释放内存 */
	entry = list;
	while (entry != NULL) {
		next = entry->next;
		free(entry);
		entry = next;
	}
}