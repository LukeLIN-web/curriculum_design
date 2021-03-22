#include <stdlib.h>
#include "queue.h"
#include "alloc-testing.h"

/* 一个双向队列 */
typedef struct _QueueEntry QueueEntry;
struct _QueueEntry {
	QueueValue data;
	QueueEntry *prev;
	QueueEntry *next;
};

struct _Queue {
	QueueEntry *head;
	QueueEntry *tail;
};

Queue *queue_new(void){
	Queue *queue;
	queue = (Queue *) malloc(sizeof(Queue));
	if (queue == NULL)
		return NULL;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void queue_free(Queue *queue){

	/* 清空队列的每个元素 */
	while (!queue_is_empty(queue))
		queue_pop_head(queue);

	/* 释放队列占有的内存 */
	free(queue);
}

QueueValue queue_pop_head(Queue *queue){
	QueueEntry *entry;
	QueueValue result;

	/* 检查队列是否为空 */
	if (queue_is_empty(queue))
		return QUEUE_NULL;

	/* 头结点从队列中脱离 */
	entry = queue->head;
	queue->head = entry->next;
	result = entry->data;
	if (queue->head == NULL)

		/* 如果脱离队列的是最后一个结点，同时将队尾指针赋为NULL */
		queue->tail = NULL;
	else

		/* 将新的队头结点的前驱指针赋为NULL */
		queue->head->prev = NULL;

	/* 释放脱离队列的结点的内存 */
	free(entry);
	return result;
}

QueueValue queue_peek_head(Queue *queue){
	if (queue_is_empty(queue))
		return QUEUE_NULL;
	else
		return queue->head->data;
}

int queue_push_tail(Queue *queue, QueueValue data){
	QueueEntry *new_entry;

	/* 创建一个新结点，并分配内存 */
	new_entry = malloc(sizeof(QueueEntry));

	if (new_entry == NULL)
		return 0;
	new_entry->data = data;
	new_entry->prev = queue->tail;
	new_entry->next = NULL;

	/* 将新结点插入队列尾部 */
	if (queue->tail == NULL) {

		/* 如果队列为空，将其head和tail指针同时指向新结点 */
		queue->head = new_entry;
		queue->tail = new_entry;
	} else {

        /* 原来队中的最后结点需要使用后驱指针指向新结点 */
		queue->tail->next = new_entry;

        /* 尾指针指向新结点 */
		queue->tail = new_entry;
	}
	return 1;
}

QueueValue queue_peek_tail(Queue *queue){
	if (queue_is_empty(queue))
		return QUEUE_NULL;
	else
		return queue->tail->data;
}

int queue_is_empty(Queue *queue){
    return queue->head == NULL;
}