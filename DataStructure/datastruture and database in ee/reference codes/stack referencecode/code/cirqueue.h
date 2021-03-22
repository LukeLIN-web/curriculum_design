typedef void *CirQueueValue;	//队列数据指针
typedef struct _CirQueue CirQueue;	//循环队列结构

/* 新建并初始化循环队列，返回队头指针 */
CirQueue *cirqueue_new(void);

/* 判断一个队列是否为空，队列非空返回零，队列为空返回非零值 */
int cirqueue_is_empty(CirQueue *cirqueue);

/* 判断一个队列是否为空，队列非满返回零，队列为满返回非零值 */
int cirqueue_is_full(CirQueue *cirqueue);

/* 将data加入队尾，添加成功返回1，队列已满返回0 */
int cirqueue_push(CirQueue *cirqueue, CirQueueValue data);

/* 队头元素出队，返回队头元素，空队列返回NULL */
CirQueueValue cirqueue_pop(CirQueue *cirqueue);

/* 清空一个队列 */
void cirqueue_free(CirQueue *cirqueue);
