/* 初始化迭代器 */
void hash_table_iterate(HashTable *hash_table, HashTableIterator *iterator){
	unsigned int chain;
	iterator->hash_table = hash_table;
	iterator->next_entry = NULL;

	/* 找到第一个结点 */
	for (chain = 0; chain < hash_table->table_size; ++chain)
		if (hash_table->table[chain] != NULL) {
			iterator->next_entry = hash_table->table[chain];
			iterator->next_chain = chain;
			break;
		}
}

/* 判断目前的结点在同一链表中是否还有后继结点 */ 
int hash_table_iter_has_more(HashTableIterator *iterator){
	return iterator->next_entry != NULL;
}

/* 迭代器进入下一个结点，返回当前结点的数据 */
HashTableValue hash_table_iter_next(HashTableIterator *iterator){
	HashTableEntry *current_entry;
	HashTable *hash_table;
	HashTableValue result;
	unsigned int chain;
	hash_table = iterator->hash_table;

	/* 所有结点都已遍历完 */
	if (iterator->next_entry == NULL)
		return HASH_TABLE_NULL;

	/* 获得当前结点的数据 */
	current_entry = iterator->next_entry;
	result = current_entry->value;

	/* 判断该链表中是否还有未被遍历的结点 */
	if (current_entry->next != NULL)

		/* 继续在当前链表遍历 */
		iterator->next_entry = current_entry->next;
	else {

		/* 该链表中所有结点都被遍历，进入下一个链表 */
		chain = iterator->next_chain + 1;

		/* 初始化指针 */
		iterator->next_entry = NULL;
		while (chain < hash_table->table_size) {

			/* 判断链表中是否有结点 */
			if (hash_table->table[chain] != NULL) {
				iterator->next_entry = hash_table->table[chain];
				break;
			}

			/* 尝试下一个链表 */
			chain++;
		}
		iterator->next_chain = chain;
	}
	return result;
}
