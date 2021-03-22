#include <stdlib.h>
#include <string.h>
#include "seqstack.h"
#include "arraylist.h"

ArrayList *seqstack_new(unsigned int length) {
	ArrayList *seqstack = arraylist_new(length);	//可调用ArrayList中函数实现
	return seqstack;
}

void seqstack_free(ArrayList *seqstack) {
	arraylist_free(seqstack);
}

int seqstack_push(ArrayList *seqstack, ArrayListValue data) {
	return arraylist_append(seqstack, data);	//在数组的尾部添加一个数据
}

ArrayListValue seqstack_pop(ArrayList *seqstack) {
	ArrayListValue result = seqstack->data[seqstack->length-1];
	arraylist_remove(seqstack, seqstack->length-1);	//移除数组尾部的一个数据
	return result;
}

ArrayListValue seqstack_peek(ArrayList *seqstack) {
	if (seqstack_is_empty(seqstack)) 
		return NULL;
	else 
		return seqstack->data[seqstack->length-1];	//返回栈顶元素
}

int seqstack_is_empty(ArrayList *seqstack) {
	return seqstack == NULL;
}