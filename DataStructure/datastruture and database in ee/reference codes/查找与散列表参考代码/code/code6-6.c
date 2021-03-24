HashTableValue hash_table_lookup(HashTable *hash_table, HashTableKey key){
	HashTableEntry *rover;
	unsigned int index;

	/* 根据关键词找到对应链表头结点的下标 */ 
	index = hash_table->hash_func(key) % hash_table->table_size;

	/* 遍历下标为index的链表直到找到关键词为key的结点 */
	rover = hash_table->table[index];
	while (rover != NULL) {
		if (hash_table->equal_func(key, rover->key) != 0)

			/* 找到目标结点，返回数据 */
			return rover->value;
		rover = rover->next;
	}

	/* 未找到结点 */
	return HASH_TABLE_NULL;
}
