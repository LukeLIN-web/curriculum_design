void slist_free(SListEntry *list){
	SListEntry *entry;
	entry = list;
	while (entry != NULL) {
		free(entry);
		entry = entry->next;
	}
}