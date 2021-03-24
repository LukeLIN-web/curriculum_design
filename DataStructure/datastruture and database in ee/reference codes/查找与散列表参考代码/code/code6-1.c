/* 定义散列表中数据的空指针. */
#define HASH_TABLE_NULL ((void *) 0)

/* 定义散列表迭代器结构. */
struct _HashTableIterator {
	HashTable *hash_table;
	HashTableEntry *next_entry;
	unsigned int next_chain;
};
typedef struct _HashTable HashTable;	/* 散列表结构. */

/* 散列表迭代器结构，用于遍历链表. */
typedef struct _HashTableIterator HashTableIterator;

/* 散列表内部结点的结构. */
typedef struct _HashTableEntry HashTableEntry;

/* 在散列表中查找数据的关键词 */
typedef void *HashTableKey;

/* 存储在散列表中的数据. */
typedef void *HashTableValue;

/* 在散列表中用来生成关键词散列数的哈希函数. */
typedef unsigned int (*HashTableHashFunc)(HashTableKey value);

/* 比较两个关键词是否相同的函数 */
typedef int (*HashTableEqualFunc)(HashTableKey value1, HashTableKey value2);

/* 用来在结点移除出散列表时释放一个关键词的函数类型. */
typedef void (*HashTableKeyFreeFunc)(HashTableKey value);

/* 用来在结点移除出散列表时释放一个数值的函数类型. */
typedef void (*HashTableValueFreeFunc)(HashTableValue value);

/* 创建一个新的散列表. */
HashTable *hash_table_new(HashTableHashFunc hash_func,
                          HashTableEqualFunc equal_func);

/* 销毁一个散列表. */
void hash_table_free(HashTable *hash_table);

/* 登记用来释放关键词和数值的函数. */
void hash_table_register_free_functions(HashTable *hash_table,
                                        HashTableKeyFreeFunc key_free_func,
                                        HashTableValueFreeFunc value_free_func);

/* 在散列表中插入一个值，将会覆写所有已存在的使用相同关键词的结点. */
int hash_table_insert(HashTable *hash_table,
                      HashTableKey key,
                      HashTableValue value);

/* 通过关键词在散列表中查找数据. */
HashTableValue hash_table_lookup(HashTable *hash_table,
                                 HashTableKey key);

/* 从散列表中移除一个值. */
int hash_table_remove(HashTable *hash_table, HashTableKey key);

/* 检索散列表中的结点个数. */
unsigned int hash_table_num_entries(HashTable *hash_table);

/* 初始化一个散列表迭代器. */
void hash_table_iterate(HashTable *hash_table, HashTableIterator *iter);

/* 判断散列表(一个链表)中是否还有关键词来遍历. */
int hash_table_iter_has_more(HashTableIterator *iterator);

/* 使用散列表迭代器来检索下一个关键词. */
HashTableValue hash_table_iter_next(HashTableIterator *iterator);