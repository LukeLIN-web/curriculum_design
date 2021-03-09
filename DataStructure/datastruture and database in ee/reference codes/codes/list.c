/*

Copyright (c) 2005-2008, Simon Howard

Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted, provided
that the above copyright notice and this permission notice appear
in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

 */

#include <stdlib.h>

#include "list.h"

/* malloc() / free() testing */

#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif

/* 双向链表结构 */

struct _ListEntry {
	ListValue data;
	ListEntry *prev;
	ListEntry *next;
};

void list_free(ListEntry *list)
{
	ListEntry *entry;

	/* 遍历所有结点，释放内存 */

	entry = list;

	while (entry != NULL) {
		ListEntry *next;

		next = entry->next;

		free(entry);

		entry = next;
	}
}

ListEntry *list_prepend(ListEntry **list, ListValue data)
{
	ListEntry *newentry;

	/* 创建新结点 */

	newentry = malloc(sizeof(ListEntry));

	if (newentry == NULL) {
		return NULL;
	}

	newentry->data = data;

	/* 在表头插入结点 */

	if (*list != NULL) {
		(*list)->prev = newentry;
	}
	newentry->prev = NULL;
	newentry->next = *list;
	*list = newentry;

	return newentry;
}

ListEntry *list_append(ListEntry **list, ListValue data)
{
	ListEntry *rover;
	ListEntry *newentry;

	/* 创建新结点 */

	newentry = malloc(sizeof(ListEntry));

	if (newentry == NULL) {
		return NULL;
	}

	newentry->data = data;
	newentry->next = NULL;

	/* 在空表表尾插入结点需不同操作 */

	if (*list == NULL) {

		/* 创建表头结点 */

		*list = newentry;
		newentry->prev = NULL;

	} else {

		/* 找到表尾结点 */

		for (rover=*list; rover->next != NULL; rover = rover->next);

		/* 添加到链表尾部 */

		newentry->prev = rover;
		rover->next = newentry;
	}

	return newentry;
}

ListValue list_data(ListEntry *listentry)
{
	return listentry->data;
}

ListEntry *list_prev(ListEntry *listentry)
{
	return listentry->prev;
}

ListEntry *list_next(ListEntry *listentry)
{
	return listentry->next;
}

ListEntry *list_nth_entry(ListEntry *list, unsigned int n)
{
	ListEntry *entry;
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

ListValue list_nth_data(ListEntry *list, unsigned int n)
{
	ListEntry *entry;

	/* 找到指定的结点 */

	entry = list_nth_entry(list, n);

	/* 如果超出范围，返回NULL，否则返回数据 */

	if (entry == NULL) {
		return LIST_NULL;
	} else {
		return entry->data;
	}
}

unsigned int list_length(ListEntry *list)
{
	ListEntry *entry;
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

ListValue *list_to_array(ListEntry *list)
{
	ListEntry *rover;
	ListValue *array;
	unsigned int length;
	unsigned int i;

	/* 分配空间给数组，数组的长度与链表长度相同 */

	length = list_length(list);

	array = malloc(sizeof(ListValue) * length);

	if (array == NULL) {
		return NULL;
	}

	/* 将所有的结点的数据加入数组中 */

	rover = list;

	for (i=0; i<length; ++i) {

		/* 把第i个结点的数据加入数组  */

		array[i] = rover->data;

		/* 进入下一个结点  */

		rover = rover->next;
	}

	return array;
}

int list_remove_entry(ListEntry **list, ListEntry *entry)
{
	/* 如果链表或待删除结点为空，返回0  */

	if (*list == NULL || entry == NULL) {
		return 0;
	}

	/* 删除第1个结点需要不同操作  */

	if (entry->prev == NULL) {

		/* 更新链表头指针，并断开头结点 */

		*list = entry->next;

		/* 如果有第2个结点，更新第2个结点的前向指针 */

		if (entry->next != NULL) {
			entry->next->prev = NULL;
		}

	} else {

		/* 不是头结点，更新待删除结点之前一个结点的后向指针 */

		entry->prev->next = entry->next;

		/* 若待删除结点的后一个结点非空，更新它的前向指针 */

		if (entry->next != NULL) {
			entry->next->prev = entry->prev;
		}
	}

	/* 释放结点内存 */

	free(entry);

	/* 删除成功返回1  */

	return 1;
}

unsigned int list_remove_data(ListEntry **list, ListEqualFunc callback,
                              ListValue data)
{
	unsigned int entries_removed;
	ListEntry *rover;
	ListEntry *next;

	entries_removed = 0;

	/* 遍历链表 */

	rover = *list;

	while (rover != NULL) {

		next = rover->next;

		if (callback(rover->data, data)) {

			/* 这个数据需要删除，将该结点从链表中断开 */

			if (rover->prev == NULL) {

				/* 该结点为头结点 */

				*list = rover->next;
			} else {

				/* 更新前一个结点的后向指针 */

				rover->prev->next = rover->next;
			}

			if (rover->next != NULL) {
				rover->next->prev = rover->prev;
			}

			/* 释放结点内存 */

			free(rover);

			++entries_removed;
		}

		/* 进入下一个结点 */

		rover = next;
	}

	return entries_removed;
}

/* 用于内部快速排序的函数，返回排序后的尾结点 */

static ListEntry *list_sort_internal(ListEntry **list,
                                     ListCompareFunc compare_func)
{
	ListEntry *pivot;
	ListEntry *rover;
	ListEntry *less_list, *more_list;
	ListEntry *less_list_end, *more_list_end;

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
		ListEntry *next = rover->next;

		if (compare_func(rover->data, pivot->data) < 0) {

			/* 把这个结点放入less list中 */

			rover->prev = NULL;
			rover->next = less_list;
			if (less_list != NULL) {
				less_list->prev = rover;
			}
			less_list = rover;

		} else {

			/* 把这个结点放入more list中 */

			rover->prev = NULL;
			rover->next = more_list;
			if (more_list != NULL) {
				more_list->prev = rover;
			}
			more_list = rover;
		}

		rover = next;
	}

	/* 对子链表递归排序 */

	less_list_end = list_sort_internal(&less_list, compare_func);
	more_list_end = list_sort_internal(&more_list, compare_func);

	/* 创新以less less为开始部分新链表 */

	*list = less_list;

	/* 把pivot结点插入less list的尾部。若less list为空，以povit为表头 */

	if (less_list == NULL) {
		pivot->prev = NULL;
		*list = pivot;
	} else {
		pivot->prev = less_list_end;
		less_list_end->next = pivot;
	}

	/* 在pivot结点后插入more list */

	pivot->next = more_list;
	if (more_list != NULL) {
		more_list->prev = pivot;
	}

	/* 返回链表的尾节点 */

	if (more_list == NULL) {
		return pivot;
	} else {
		return more_list_end;
	}
}

void list_sort(ListEntry **list, ListCompareFunc compare_func)
{
	list_sort_internal(list, compare_func);
}

ListEntry *list_find_data(ListEntry *list,
                          ListEqualFunc callback,
                          ListValue data)
{
	ListEntry *rover;

	/* 遍历链表，直到找到存有指定数据的结点 */

	for (rover=list; rover != NULL; rover=rover->next) {
		if (callback(rover->data, data) != 0) {
			return rover;
		}
	}

	/* 未找到 */

	return NULL;
}

void list_iterate(ListEntry **list, ListIterator *iter)
{
	/* 从表头开始遍历 */

	iter->prev_next = list;

	/* 还未读入第一个结点，当前遍历到的位置置为空指针 */

	iter->current = NULL;
}

int list_iter_has_more(ListIterator *iter)
{
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

ListValue list_iter_next(ListIterator *iter)
{
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
		return LIST_NULL;
	} else {
		return iter->current->data;
	}
}

void list_iter_remove(ListIterator *iter)
{
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* 第一个结点还未读入，或已遍历至表尾，或当前遍历到的位置
		 * 的结点已删除，则不进行操作 */

	} else {

		/* 删除当前遍历到的位置的结点 */

		*iter->prev_next = iter->current->next;

		if (iter->current->next != NULL) {
			iter->current->next->prev = iter->current->prev;
		}

		free(iter->current);
		iter->current = NULL;
	}
}

