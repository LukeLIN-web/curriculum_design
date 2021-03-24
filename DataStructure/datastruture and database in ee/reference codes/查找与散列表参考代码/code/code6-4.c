HashTable *hash_table_new(HashTableHashFunc hash_func,
                          HashTableEqualFunc equal_func){
	HashTable *hash_table;

	/* 分配一个内存空间 */
	hash_table = (HashTable *) malloc(sizeof(HashTable));
	if (hash_table == NULL)
		return NULL;
	hash_table->hash_func = hash_func;
	hash_table->equal_func = equal_func;
	hash_table->key_free_func = NULL;
	hash_table->value_free_func = NULL;
	hash_table->entries = 0;
	hash_table->prime_index = 0;

	/* 给每个结点分配内存空间，结点数量为table_size */
	if (!hash_table_allocate_table(hash_table)) {
		free(hash_table);
		return NULL;
	}
	return hash_table;
}
