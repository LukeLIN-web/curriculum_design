#include <stdlib.h>
#include "cirqueue.h"

#define MaxQueueSize 20	/* 数组的大小 */

struct _CirQueue {
	CirQueueValue data[MaxQueueSize];	/* 定义存放队列元素的数组 */
	int head;	/* 指示队首下标 */
	int tail;	/* 指示队尾下标 */
};

CirQueue *cirqueue_new(void){
	int i;
	CirQueue *cirqueue;
	cirqueue = (CirQueue *)malloc(sizeof(CirQueue));	/* 为队列结构分配内存 */
	for(i = 0; i < MaxQueueSize; i++)
		cirqueue->data[i] = NULL;	//data初始化为空指针 
	cirqueue->head = cirqueue->tail = -1;
	return cirqueue;
}

int cirqueue_is_empty(CirQueue *cirqueue){
	return cirqueue->head == cirqueue->tail;	//变量head和tail值相同，则队列为空
}

int cirqueue_is_full(CirQueue *cirqueue){
	return (cirqueue->tail + 1) % MaxQueueSize == cirqueue->head;
}

int cirqueue_push(CirQueue *cirqueue, CirQueueValue data){
	if(cirqueue_is_full(cirqueue))
		return 0;	//数组已满则返回0
	cirqueue->tail = (cirqueue->tail + 1) % MaxQueueSize;	/* 队尾下标+1并取对MaxQueueSize的余数 */
	cirqueue->data[cirqueue->tail] = data;
	return 1;
}

CirQueueValue cirqueue_pop(CirQueue *cirqueue){
	CirQueueValue result;
	if (cirqueue_is_empty(cirqueue))
		return NULL;	//队列为空则返回空指针
	result = cirqueue->data[(cirqueue->head + 1) % MaxQueueSize];
	cirqueue->head = (cirqueue->head + 1) % MaxQueueSize;	/* 队首下标+1并取对MaxQueueSize的余数 */
	return result;
}

void cirqueue_free(CirQueue *cirqueue){
	int i;
	for(i = 0; i < MaxQueueSize; i++)
		free(cirqueue->data[i]);	//释放指针数组内存空间
	free(cirqueue);
}
