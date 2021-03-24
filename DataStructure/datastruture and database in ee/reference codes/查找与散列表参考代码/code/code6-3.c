struct _HashTableEntry {
	HashTableKey key;
	HashTableValue value;
	HashTableEntry *next;
};