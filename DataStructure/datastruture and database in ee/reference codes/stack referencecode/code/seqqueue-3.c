#include <stdio.h>
#include "seqqueue.h"

#define MaxQueueSize 20	/* 队列中的最大元素 */

struct _SeqQueue {
    SeqQueueValue array[MaxQueueSize];
    int len;	//队列当前长度
};

SeqQueue *seqqueue_new(void){
    SeqQueue *seqqueue;
    seqqueue = (SeqQueue *)malloc(sizeof(SeqQueue));
    seqqueue->len = 0;	//初始长度为0 
    return seqqueue;
}

void seqqueue_free(SeqQueue *seqqueue){
	int i;
	for(i = 0; i < seqqueue->len; i++) 
		free(seqqueue->array[i]);	//释放指针数组空间 
    free(seqqueue);
}

int seqqueue_length(SeqQueue *seqqueue){
    return seqqueue->len;
}

int seqqueue_is_empty(SeqQueue *seqqueue){
	return seqqueue->len == 0;
}

int seqqueue_is_full(SeqQueue *seqqueue){
	return seqqueue->len == MaxQueueSize;
}

SeqQueueValue seqqueue_peek(SeqQueue *seqqueue){
	return seqqueue->array[0];
}

void seqqueue_clear(SeqQueue *seqqueue){
	seqqueue->len = 0;
}