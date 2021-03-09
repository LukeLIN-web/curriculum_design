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

/**
 * @file list.h
 *
 * @brief Doubly-linked list.
 *
 * A doubly-linked list stores a collection of values.  Each entry in
 * the list (represented by a pointer a @ref ListEntry structure)
 * contains a link to the next entry and the previous entry.
 * It is therefore possible to iterate over entries in the list in either
 * direction.
 *
 * To create an empty list, create a new variable which is a pointer to
 * a @ref ListEntry structure, and initialise it to NULL.
 * To destroy an entire list, use @ref list_free.
 *
 * To add a value to a list, use @ref list_append or @ref list_prepend.
 *
 * To remove a value from a list, use @ref list_remove_entry or
 * @ref list_remove_data.
 *
 * To iterate over entries in a list, use @ref list_iterate to initialise
 * a @ref ListIterator structure, with @ref list_iter_next and
 * @ref list_iter_has_more to retrieve each value in turn.
 * @ref list_iter_remove can be used to remove the current entry.
 *
 * To access an entry in the list by index, use @ref list_nth_entry or
 * @ref list_nth_data.
 *
 * To sort a list, use @ref list_sort.
 *
 */

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 双向链表结构.
 */

typedef struct _ListEntry ListEntry;

/**
 * 链表迭代器结构，用于遍历链表.
 */

typedef struct _ListIterator ListIterator;

/**
 * 指向链表中存储的数据的指针
 */

typedef void *ListValue;

/**
 * 定义链表迭代器结构，参考@ref ListIterator.
 */

struct _ListIterator {
	ListEntry **prev_next;
	ListEntry *current;
};

/**
 * 定义链表中数据的空指针，参考@ref.
 */

#define LIST_NULL ((void *) 0)

/**
 * 在排序时比较链表中两个元素数据的函数.
 *
 * @return    如果value1应排在value2之前，返回正数,
 *            如果value1应排在value2后面，返回负数,
 *            如果value1 and value2相等，返回0.
 */

typedef int (*ListCompareFunc)(ListValue value1, ListValue value2);

/**
 * 判断链表中两个元素数据是否相等.
 *
 * @return   如果value1 and value2相等,返回非零值，如果不相等返回0.
 */

typedef int (*ListEqualFunc)(ListValue value1, ListValue value2);

/**
 * 释放整个链表内存.
 *
 * @param list      表头指针.
 */

void list_free(ListEntry *list);

/**
 * Prepend a value to the start of a list.
 *
 * 在链表头插入结点.
 *
 * @param list      表头指针.
 * @param data      待插入的数据.
 * @return          返回新结点的指针，如果新结点内存分配失败，返回NULL.
 */

ListEntry *list_prepend(ListEntry **list, ListValue data);

/**
 * 在链表尾插入结点.
 *
 * @param list      表头指针.
 * @param data      待插入的数据.
 * @return          返回新结点的指针，如果新结点内存分配失败，返回NULL.
 */

ListEntry *list_append(ListEntry **list, ListValue data);

/**
 * 获取链表中上一个结点的指针.
 *
 * @param listentry    结点指针.
 * @return             返回上一个结点的指针，若当前为第一个结点则返回NULL.
 */

ListEntry *list_prev(ListEntry *listentry);

/**
 * 获取链表中下一个结点的指针.
 *
 * @param listentry    结点指针.
 * @return             返回下一个结点的指针，若当前为尾结点则返回NULL.
 */

ListEntry *list_next(ListEntry *listentry);

/**
 * 返回结点中存储的数据.
 *
 * @param listentry    结点指针.
 * @return             返回结点中的数据.
 */

ListValue list_data(ListEntry *listentry);

/**
 * 得到指向第n个结点的指针.
 *
 * @param list       表头指针.
 * @param n          序号.
 * @return           返回序号为n的结点指针，如果序号超出范围返回NULL.
 */

ListEntry *list_nth_entry(ListEntry *list, unsigned int n);

/**
 * 获取第n个结点的数据.
 *
 * @param list       表头指针.
 * @param n          序号.
 * @return           返回序号为n的结点的数据，如果失败返回SLIST_NULL，参考@ref.
 */

ListValue list_nth_data(ListEntry *list, unsigned int n);

/**
 * 得到链表的长度
 *
 * @param list       表头指针.
 * @return           返回链表中结点的个数.
 */

unsigned int list_length(ListEntry *list);

/**
 * 创建一个包含链表中内容的数组.
 *
 * @param list       表头指针.
 * @return           返回新建的数组，如果数组内存申请失败返回NULL.
 *                   数组的长度和链表的长度相等(参考@ref list_length).
 */

ListValue *list_to_array(ListEntry *list);

/**
 * 删除一个结点.
 *
 * @param list       表头指针.
 * @param entry      待删除结点.
 * @return           成功删除返回非零数，结点不存在返回零.
 */

int list_remove_entry(ListEntry **list, ListEntry *entry);

/**
 * 删除所有存有特定数据的结点.
 *
 * @param list       表头指针.
 * @param callback   Callback函数用于比较表中数据与待删除数据.
 * @param data       需要删除的数据.
 * @return           返回删除的结点数.
 */

unsigned int list_remove_data(ListEntry **list, ListEqualFunc callback,
                              ListValue data);

/**
 * 对链表排序
 *
 * @param list          表头指针.
 * @param compare_func  函数用于比较结点中的数据，由用户定义.
 */

void list_sort(ListEntry **list, ListCompareFunc compare_func);

/**
 *查找存有特定数据的结点
 *
 * @param list           表头指针.
 * @param callback       Callback函数用于比较表中数据与待查找的数据是否相等.
 * @param data           待查找数据.
 * @return               返回找到的第一个结点，若未找到返回NULL.
 */

ListEntry *list_find_data(ListEntry *list,
                          ListEqualFunc callback,
                          ListValue data);

/**
 * 初始化一个链表迭代器，用于遍历链表，参考@ref.
 *
 * @param list           表头指针.
 * @param iter           指向初始化的链表迭代器的指针，参考@ref.
 */

void list_iterate(ListEntry **list, ListIterator *iter);

/**
 * 判断链表中是否还有更多数据待遍历.没有返回0，有则返回非零数
 *
 * @param iterator       链表迭代器.
 * @return               还有更多的数据待遍历则返回非零数，没有则返回0.
 */

int list_iter_has_more(ListIterator *iterator);

/**
 * 用链表迭代器获取链表中的下一个数据.
 *
 * @param iterator       链表迭代器.
 * @return               返回下一个数据，如果不存在则返回LIST_NULL.
 */

ListValue list_iter_next(ListIterator *iterator);

/**
 * 删除当前遍历到的位置的结点(最后一次从 slist_iter_next返回的数据，参考@ref)
 *
 * @param iterator       链表迭代器.
 */

void list_iter_remove(ListIterator *iterator);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_LIST_H */

