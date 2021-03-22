#include "list.h"

/* 销毁一个队列并释放内存. */
void lqueue_free(ListEntry *lqueue);

/* 从队列头部删除一个元素，返回队头元素，如果队列为空，返回NULL. */
ListValue lqueue_pop(ListEntry **lqueue);

/* 从队列头部获得一个元素且不将其删除，返回队头元素，如果队列为空，返回NULL. */
ListValue lqueue_peek(ListEntry *lqueue);

/* 加入新元素到队尾，如果添加成功返回非零值，无法分配内存返回零. */
ListEntry *lqueue_push(ListEntry **lqueue, ListValue data);

/* 判断一个队列是否为空，队列非空返回零，队列为空返回非零值. */
int lqueue_is_empty(ListEntry *lqueue);

/* 获取队列长度 */
int lqueue_length(ListEntry *lqueue);
