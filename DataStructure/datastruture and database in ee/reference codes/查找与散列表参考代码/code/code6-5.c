int hash_table_insert(HashTable *hash_table, HashTableKey key,
                      HashTableValue value){
	HashTableEntry *rover;
	HashTableEntry *newentry;
	unsigned int index;
	
	/* 如果表中的结点过多，冲突的可能性增大，散列表的查找效率下降，此时扩大表的大小 */
	/* 当已使用的结点数量超过散列表大小的1/3 */ 
	if ((hash_table->entries * 3) / hash_table->table_size > 0)
		if (!hash_table_enlarge(hash_table))

			/* 分配内存失败 */
			return 0;

	/* 根据关键词找到对应链表头结点的下标 */ 
	index = hash_table->hash_func(key) % hash_table->table_size;

	/* 遍历整个链表来查找是否有相同关键词的结点，有则覆写，否则添加 */
	rover = hash_table->table[index];
	while (rover != NULL) {
		if (hash_table->equal_func(rover->key, key) != 0) {

			/* 若找到相同关键词，用新数据覆写结点 */
			/* 如果有释放数值和关键词内存的函数，那么释放旧内存，没有则跳过 */
			if (hash_table->value_free_func != NULL)
				hash_table->value_free_func(rover->value);
			if (hash_table->key_free_func != NULL)
				hash_table->key_free_func(rover->key);
			rover->key = key;
			rover->value = value;
			
			/* 覆写完成 */
			return 1;
		}
		rover = rover->next;
	}

	/* 没有关键词为key的结点，那么在新建一个并加入链表头部 */
	newentry = (HashTableEntry *) malloc(sizeof(HashTableEntry));
	if (newentry == NULL)
		return 0;
	newentry->key = key;
	newentry->value = value;

	/* 插入序号为index的链表头部 */ 
	newentry->next = hash_table->table[index];
	hash_table->table[index] = newentry;

	/* 链表中结点的数量增加1 */
	hash_table->entries++;

	/* 添加完成 */
	return 1;
}
