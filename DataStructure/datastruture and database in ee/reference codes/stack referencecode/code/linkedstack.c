#include<stdio.h>
#include <stdlib.h>
#include "linkedstack.h"
#include "slist.h"

void linkedstack_free(SListEntry *linkedStack) {
	slist_free(linkedStack);	//可调用SList中函数实现
}

SListEntry *linkedstack_push(SListEntry **linkedStack, SListValue data) {
	return slist_prepend(linkedStack, data);	//在链表头插入数据
}

SListValue linkedstack_pop(SListEntry **linkedStack) {
	SListValue result = slist_nth_data(*linkedStack, 0);
	if(slist_remove_entry(linkedStack, *linkedStack))	//移除链表头的数据
		return result;
	return SLIST_NULL;
}

SListValue linkedstack_peek(SListEntry *linkedStack) {
	return slist_nth_data(linkedStack, 0);	//返回链表头的数据指针
}

int linkedstack_is_empty(SListEntry *linkedStack) {
	return slist_is_empty(linkedStack);
}