struct _HashTable {
	HashTableEntry **table;
	unsigned int table_size;
	HashTableHashFunc hash_func;
	HashTableEqualFunc equal_func;
	HashTableKeyFreeFunc key_free_func;
	HashTableValueFreeFunc value_free_func;
	unsigned int entries;
	unsigned int prime_index;
};