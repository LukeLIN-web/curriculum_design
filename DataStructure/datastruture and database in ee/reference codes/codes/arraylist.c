#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#define MIN_LENGTH 5

ArrayList *arraylist_new(unsigned int length){
	ArrayList *new_arraylist;
	if (length <= 0)	/* 如果数组的长度不合法(小于等于0)，使用一个合理的默认值 */
		length = MIN_LENGTH;
	/* 给一个新的动态数组分配空间，并且进行赋值 */
	new_arraylist = (ArrayList *) malloc(sizeof(ArrayList));
	if (new_arraylist == NULL)
		return NULL;
	new_arraylist->_alloced = length;
	new_arraylist->length = 0;
	/* 给data分配内存地址 */
	new_arraylist->data = malloc(length * sizeof(ArrayListValue));
	if (new_arraylist->data == NULL) {
		free(new_arraylist);
		return NULL;
	}
	return new_arraylist;
}

void arraylist_free(ArrayList *arraylist){
	if (arraylist != NULL) {
		free(arraylist->data);
		free(arraylist);
	}
}

static int arraylist_enlarge(ArrayList *arraylist){
	ArrayListValue *data;
	unsigned int newsize;
	newsize = arraylist->_alloced * 2;	/* 将已分配的数组内存空间扩展为原来的2倍 */
	/* 给数组重新分配新的内存空间 */
	data = realloc(arraylist->data, sizeof(ArrayListValue) * newsize);
	if (data == NULL) 
		return 0;
	else {
		arraylist->data = data;
		arraylist->_alloced = newsize;
		return 1;
	}
}

int arraylist_insert(ArrayList *arraylist, unsigned int index,
                     ArrayListValue data){
	if (index > arraylist->length)	/* 检查下标是否越界 */
		return 0;
	if (arraylist->length + 1 > arraylist->_alloced)	/* 必要时扩展数组长度 */
		if (!arraylist_enlarge(arraylist))
			return 0;
	/* 把待插入位置及之后的数组内容后移一位 */
	memmove(&arraylist->data[index + 1],&arraylist->data[index],
	        (arraylist->length - index) * sizeof(ArrayListValue));	
	arraylist->data[index] = data;	/*在下标为index的位置插入数据 */
	++arraylist->length;
	return 1;
}

int arraylist_append(ArrayList *arraylist, ArrayListValue data){
	return arraylist_insert(arraylist, arraylist->length, data);
}

int arraylist_prepend(ArrayList *arraylist, ArrayListValue data){
	return arraylist_insert(arraylist, 0, data);
}

void arraylist_remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length){
	/* 检查范围是否合法 */
	if (index > arraylist->length || index + length > arraylist->length)
		return;
	/* 把移除范围之后数组的内容前移 */
	memmove(&arraylist->data[index],&arraylist->data[index + length],
	        (arraylist->length - (index + length))
			 * sizeof(ArrayListValue));
	arraylist->length -= length;	/* 新数组的长度 */
}

void arraylist_remove(ArrayList *arraylist, unsigned int index){
	arraylist_remove_range(arraylist, index, 1);
}

int arraylist_index_of(ArrayList *arraylist,ArrayListEqualFunc callback,
                       ArrayListValue data){
	unsigned int i;
	for (i=0; i<arraylist->length; ++i)
		if (callback(arraylist->data[i], data) != 0)
			return (int) i;
	return -1;
}

void arraylist_clear(ArrayList *arraylist){
	arraylist->length = 0;	/* 将数组长度设为0即可清空数组 */
}