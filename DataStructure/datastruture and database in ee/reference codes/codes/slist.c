#include <stdlib.h>

#include "slist.h"

/* malloc() / free() testing */

#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif

/* 单向链表结构 */

struct _SListEntry {
	SListValue data;
	SListEntry *next;
};

int slist_is_empty(SListEntry *list) {
    return list == NULL;
}

int slist_is_last(SListEntry *listentry) {
    return listentry->next == NULL;
}

void slist_free(SListEntry *list) {
	SListEntry *entry;

	/* 遍历所有结点，释放内存 */
	entry = list;
	while (entry != NULL) {
		SListEntry *next;
		next = entry->next;
		free(entry);
		entry = next;
	}
}

SListEntry *slist_prepend(SListEntry **list, SListValue data) {
	SListEntry *newentry;

	/* 创建新结点 */
    newentry = malloc(sizeof(SListEntry));
	if (newentry == NULL) {
		return NULL;
	}
	newentry->data = data;

	/* 在表头插入结点 */
	newentry->next = *list;
	*list = newentry;
	return newentry;
}

SListEntry *slist_append(SListEntry **list, SListValue data) {
	SListEntry *rover;
	SListEntry *newentry;

	/* 创建新结点 */
	newentry = malloc(sizeof(SListEntry));
	if (newentry == NULL) {
		return NULL;
	}
	newentry->data = data;
	newentry->next = NULL;

	/* 在空表表尾插入结点需不同操作 */
	if (*list == NULL) {

		/* 创建表头结点 */
		*list = newentry;
	} else {

		/* 找到表尾结点 */
		for (rover=*list; rover->next != NULL; rover = rover->next);

		/* 添加到链表尾部 */
		rover->next = newentry;
	}
	return newentry;
}

SListValue slist_data(SListEntry *listentry) {
	return listentry->data;
}

SListEntry *slist_next(SListEntry *listentry) {
	return listentry->next;
}

SListEntry *slist_nth_entry(SListEntry *list, unsigned int n) {
	SListEntry *entry;
	unsigned int i;

	/* 通过n个链表结点到达所需结点，并且确保没有达到表尾 */

	entry = list;
	for (i=0; i<n; ++i) {
		if (entry == NULL) {
			return NULL;
		}
		entry = entry->next;
	}

	return entry;
}

SListValue slist_nth_data(SListEntry *list, unsigned int n) {
	SListEntry *entry;

	/* 找到指定的结点 */
	entry = slist_nth_entry(list, n);

	/* 如果超出范围，返回NULL，否则返回数据 */
	if (entry == NULL) {
		return SLIST_NULL;
	} else {
		return entry->data;
	}
}

unsigned int slist_length(SListEntry *list) {
	SListEntry *entry;
	unsigned int length;
	length = 0;
	entry = list;
	while (entry != NULL) {

		/* 计算结点的数量 */

		++length;
		entry = entry->next;
	}
	return length;
}

SListValue *slist_to_array(SListEntry *list) {
	SListEntry *rover;
	SListValue *array;
	unsigned int length;
	unsigned int i;

	/* 分配空间给数组，数组的长度与链表长度相同 */
	length = slist_length(list);
	array = malloc(sizeof(SListValue) * length);
	if (array == NULL) {
		return NULL;
	}

	/* 将所有的结点的数据加入数组中 */
	rover = list;
	for (i=0; i<length; ++i) {

		/* 把第i个结点的数据加入数组 */
		array[i] = rover->data;

		/* 进入下一个结点 */
		rover = rover->next;
	}
	return array;
}

int slist_remove_entry(SListEntry **list, SListEntry *entry){
	SListEntry *rover;

	/* 如果链表或待删除结点为空，返回0 */
	if (*list == NULL || entry == NULL)
		return 0;

	/* 删除头结点需要不同操作 */
	if (*list == entry)

		/* 更新链表头指针，并断开头结点 */
		*list = entry->next;
    else {

		/* 搜索链表寻找前驱结点 */
		rover = *list;
		while (rover != NULL && rover->next != entry)
			rover = rover->next;
		if (rover == NULL)
			return 0;   /* 未找到 */
	    else

			/* rover->next现在指向entry, 所以rover是前驱结点，entry从链表中脱离 */
			rover->next = entry->next;
	}
	free(entry);    /* 释放结点内存 */
	return 1;   /* 操作成功 */
}

unsigned int slist_remove_data(SListEntry **list, SListEqualFunc callback,
                               SListValue data) {
	SListEntry **rover;
	SListEntry *next;
	unsigned int entries_removed;
	entries_removed = 0;

	/* 遍历链表 */
	rover = list;
	while (*rover != NULL) {

		/* 判断结点是否需要删除 */
		if (callback((*rover)->data, data) != 0) {
			next = (*rover)->next;
			free(*rover);
			*rover = next;

			/* 对删除的结点计数 */
			++entries_removed;
		} else {

			/* 进入下一个结点 */
			rover = &((*rover)->next);
		}
	}
	return entries_removed;
}

/* 用于内部快速排序的函数，返回排序后的尾结点 */

static SListEntry *slist_sort_internal(SListEntry **list,
                                       SListCompareFunc compare_func) {
	SListEntry *pivot;
	SListEntry *rover;
	SListEntry *less_list, *more_list;
	SListEntry *less_list_end, *more_list_end;

	/* 如果数据少于2个，则已经完成排序 */

	if (*list == NULL || (*list)->next == NULL) {
		return *list;
	}

	/* pivot指向头结点 */

	pivot = *list;

	/* 从第二个结点开始遍历链表。根据每个结点与头结点比较的结果，将
	 * 结点归入less list和more list两个子链表中 */

	less_list = NULL;
	more_list = NULL;
	rover = (*list)->next;

	while (rover != NULL) {
		SListEntry *next = rover->next;

		if (compare_func(rover->data, pivot->data) < 0) {

			/* 把这个结点放入less list中 */

			rover->next = less_list;
			less_list = rover;

		} else {

			/* 把这个结点放入more list中 */

			rover->next = more_list;
			more_list = rover;

		}

		rover = next;
	}

	/* 对子链表递归排序 */

	less_list_end = slist_sort_internal(&less_list, compare_func);
	more_list_end = slist_sort_internal(&more_list, compare_func);

	/* 创新以less less为开始部分新链表 */

	*list = less_list;

	/* 把pivot结点插入less list的尾部。若less list为空，以povit为表头 */

	if (less_list == NULL) {
		*list = pivot;
	} else {
		less_list_end->next = pivot;
	}

	/* 在pivot结点后插入more list */

	pivot->next = more_list;

	/* 返回链表的尾节点 */

	if (more_list == NULL) {
		return pivot;
	} else {
		return more_list_end;
	}
}

void slist_sort(SListEntry **list, SListCompareFunc compare_func) {
	slist_sort_internal(list, compare_func);
}

SListEntry *slist_find_data(SListEntry *list,
                            SListEqualFunc callback,
                            SListValue data) {
	SListEntry *rover;

	/* 遍历链表，直到找到存有指定数据的结点 */

	for (rover=list; rover != NULL; rover=rover->next) {
		if (callback(rover->data, data) != 0) {
			return rover;
		}
	}

	/* 未找到 */

	return NULL;
}

void slist_iterate(SListEntry **list, SListIterator *iter) {
	/* 从表头开始遍历. */
    iter->prev_next = list;

	/* 还未读入第一个结点，当前遍历到的位置置为空指针 */
    iter->current = NULL;
}

int slist_iter_has_more(SListIterator *iter) {
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* 第一个结点还未读入，或已遍历至表尾，或当前遍历到的
		 * 位置的结点已删除，用 prev_next判断是否存在下一个待
		 * 遍历结点 */

		return *iter->prev_next != NULL;

	} else {

		/* 当前遍历到的位置的结点存在，用 current->next判断
		 * 是否存在下一个结点 */

		return iter->current->next != NULL;
	}
}

SListValue slist_iter_next(SListIterator *iter) {
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* 第一个结点还未读入，或已遍历至表尾，或当前遍历到的位置
		 * 的结点已删除，从prev_next得到下一个结点 */
		iter->current = *iter->prev_next;
	} else {

		/* 当前遍历到的位置的结点存在，则遍历下一个结点 */
		iter->prev_next = &iter->current->next;
		iter->current = iter->current->next;
	}

	/* 判断当前遍历到的位置是否在表尾 */
	if (iter->current == NULL) {
		return SLIST_NULL;
	} else {
		return iter->current->data;
	}
}

void slist_iter_remove(SListIterator *iter) {
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* 第一个结点还未读入，或已遍历至表尾，或当前遍历到的位置
		 * 的结点已删除，则不进行操作 */

	} else {

		/* 删除当前遍历到的位置的结点 */

		*iter->prev_next = iter->current->next;
		free(iter->current);
		iter->current = NULL;
	}
}

/* 在结点listentry之后插入一个新的结点，返回新结点的指针 */
SListEntry *slist_insert(SListEntry **list, SListEntry *listentry, SListValue data) {
	SListEntry *newentry;
	newentry = (SListEntry *)malloc(sizeof(SListEntry));
	if(newentry == NULL)
	    return NULL;
	newentry->data = data;
	newentry->next = listentry->next;
	listentry->next = newentry;
	return newentry;
}
