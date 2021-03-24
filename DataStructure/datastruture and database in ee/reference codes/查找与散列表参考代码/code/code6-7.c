int hash_table_remove(HashTable *hash_table, HashTableKey key){
	HashTableEntry **rover;
	HashTableEntry *entry;
	unsigned int index;
	int result;

	/* 根据关键词找到对应链表头结点的下标 */ 
	index = hash_table->hash_func(key) % hash_table->table_size;
	result = 0;
	rover = &hash_table->table[index];
	while (*rover != NULL) {
		if (hash_table->equal_func(key, (*rover)->key) != 0) {

			/* 找到将要被移除的结点 */
			entry = *rover;

			/* 从链表中脱离 */
			*rover = entry->next;

			/* 销毁结点结构 */
			hash_table_free_entry(hash_table, entry);
			hash_table->entries--;
			result = 1;
			break;
		}

		/* 探查链表的下一个结点 */
		rover = &((*rover)->next);
	}
	return result;
}
