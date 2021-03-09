/* 定义判断两个值是否相等的函数类型. */
typedef int (*SListEqualFunc)(SListValue value1, SListValue value2);


/* 在排序时比较链表中两个元素数据的函数. */
typedef int (*SListCompareFunc)(SListValue value1, SListValue value2);

typedef struct _SListEntry SListEntry;  /* 单向链表结构. */
typedef struct _SListIterator SListIterator;    /* 链表迭代器结构，用于遍历链表. */

/* 这里利用到了void指针，表示SListValue可以是任意数据类型，例如int、float或自定义结构体. */
typedef void *SListValue;   /* 指向链表中存储的数据的指针. */

/* 定义链表迭代器结构. */
struct _SListIterator {
	SListEntry **prev_next;
	SListEntry *current;
};

#define SLIST_NULL ((void *) 0)    /* 定义链表中数据的空指针. */
int slist_is_empty(SListEntry *list);   /* 判断表是否为空表，空表返回1. */
int slist_is_last(SListEntry *listentry);   /* 判断listentry是否为表中的最后一个结点，如果是最后一个结点返回1. */
void slist_free(SListEntry *list);  /* 删除表并释放表所占用的内存. */
SListEntry *slist_prepend(SListEntry **list, SListValue data);  /* 添加新结点到表头部，返回指向新结点的指针. */
SListEntry *slist_append(SListEntry **list, SListValue data);   /* 添加新结点到表尾部，返回指向新结点的指针. */
SListEntry *slist_next(SListEntry *listentry);  /* 获得表中该结点的下一个结点. */
SListValue slist_data(SListEntry *listentry);   /* 获得结点中存储的数据. */
unsigned int slist_length(SListEntry *list);    /* 获得链表的长度，返回长度. */
int slist_remove_entry(SListEntry **list, SListEntry *entry);   /* 从链表中移除一个结点，找到并移除后返回1，否则返回0. */
SListEntry *slist_insert(SListEntry **list, SListEntry *listentry, SListValue data);    /* 向链表中插入一个结点. */

/* 得到指向第n个结点的指针，返回序号为n的结点指针，如果序号超出范围返回NULL. */
SListEntry *slist_nth_entry(SListEntry *list, unsigned int n);

/* 获取第n个结点的数据.返回序号为n的结点的数据，如果失败返回SLIST_NULL. */
SListValue slist_nth_data(SListEntry *list, unsigned int n);

/* 创建一个包含链表中内容的数组，返回新建的数组，内存申请失败返回NULL，数组长度与链表相等. */
SListValue *slist_to_array(SListEntry *list);

/* 查找存有特定数据的结点，返回找到的第一个结点，若未找到返回NULL.
 * Callback函数用于比较表中数据与待查找的数据是否相等. */
SListEntry *slist_find_data(SListEntry *list,
                            SListEqualFunc callback,
                            SListValue data);

/* 初始化一个链表迭代器，用于遍历链表，返回指向初始化的链表迭代器的指针. */
void slist_iterate(SListEntry **list, SListIterator *iter);

/* 判断链表中是否还有更多数据待遍历.iterator为链表迭代器.没有返回0，有则返回非零数. */
int slist_iter_has_more(SListIterator *iterator);

/* 用链表迭代器获取链表中的下一个结点. */
SListValue slist_iter_next(SListIterator *iterator);

/* 删除当前遍历到的位置的结点(最后一次从 slist_iter_next返回的数据)，iterator为链表迭代器. */
void slist_iter_remove(SListIterator *iterator);