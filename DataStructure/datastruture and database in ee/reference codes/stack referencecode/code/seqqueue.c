#include <stdio.h>
#include "genlib.h"
#include "seqqueue.h"

#define MaxQueueSize 10	/* 队列中的最大元素 */

/* 数组实现队列的结构 */ 
struct _Queue {
    void *array[MaxQueueSize];
    int len;
};

/* 新建一个队列 */ 
Queue *new_queue(void){
    Queue *queue;
    queue = (queue *)malloc(sizeof(Queue));
    queue->len = 0;
    return queue;
}

/* 释放一个队列占用的内存 */ 
void queue_free(Queue *queue){
    FreeBlock(queue);
}

/* 向队列中加入一个新元素 */ 
void queue_push_tail(Queue *queue, QueueValue data){
    if (queue->len == MaxQueueSize) 	/* 要求队列未满 */
        Error("Enqueue called on a full queue");
    queue->array[queue->len++] = data;
}

/* 移除队头的元素，并返回该元素的值 */ 
QueueValue queue_pop_head(Queue *queue){
    void *result;
    int i;
    if (queue->len == 0)    /* 要求队列非空  */
        Error("Dequeue of empty queue");
    result = queue->array[0];
    
    /* 队列中剩下的元素向队头移动一位 */
    for (i = 1; i < queue->len; i++)
        queue->array[i - 1] = queue->array[i];
    queue->len--;
    return result;
}

/* 返回队列中的元素个数 */ 
int queue_length(Queue *queue){
    return (queue->len);
}

/* 判断队列是否为空 */
int queue_is_empty(Queue *queue){
	return queue->len == 0;
}

/* 判断队列是否已满 */
int queue_is_full(Queue *queue){
	return queue->len == MaxQueueSize;
}

/* 返回队头元素 */
QueueValue queue_peek_head(Queue *queue){
	return queue->array[0];
}

/* 清除队列中全部元素 */
void queue_clear(Queue *queue){
	queue->len = 0;
}