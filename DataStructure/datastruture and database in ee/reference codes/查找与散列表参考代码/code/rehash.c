static int hash_table_enlarge(HashTable *hash_table) {
	HashTableEntry **old_table;
	unsigned int old_table_size;
	unsigned int old_prime_index;
	HashTableEntry *rover;
	HashTableEntry *next;
	unsigned int index;
	unsigned int i;

	/* 复制一份旧表结构并存储 */
	old_table = hash_table->table;
	old_table_size = hash_table->table_size;
	old_prime_index = hash_table->prime_index;

	/* 给一个新的表分配更大的内存 */
	++hash_table->prime_index;

	if (!hash_table_allocate_table(hash_table)) {

		/* 为新表分配内存失败 */
		hash_table->table = old_table;
		hash_table->table_size = old_table_size;
		hash_table->prime_index = old_prime_index;
		return 0;
	}

	/* 把所有结点链接进新生成的表中 */
	for (i=0; i < old_table_size; ++i) {
		rover = old_table[i];

		while (rover != NULL) {
			next = rover->next;

			/* 在新的表中找到原关键词对应的链表序号 */
			index = hash_table->hash_func(rover->key)
			      % hash_table->table_size;

			/* 把结点接入序号是index的链表 */
			rover->next = hash_table->table[index];
			hash_table->table[index] = rover;

			/* 链表中的下一个 */
			rover = next;
		}
	}

	/* 释放旧表的占用的内存 */
	free(old_table);
	return 1;
}
