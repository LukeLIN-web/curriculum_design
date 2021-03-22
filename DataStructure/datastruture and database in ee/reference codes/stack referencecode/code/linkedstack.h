#ifndef ALGORITHM_LINKEDSTACK_H
#define ALGORITHM_LINKEDSTACK_H
#ifdef __cplusplus
extern "C" {
#endif
#include "slist.h" 

/* 销毁一个链式栈 */
void linkedstack_free(SListEntry *linkedStack);

/* 在栈顶插入元素 */
SListEntry *linkedstack_push(SListEntry **linkedStack, SListValue data);

/* 从栈中删除栈顶元素 */
SListValue linkedstack_pop(SListEntry **linkedStack);

/* 读取栈顶元素 */
SListValue linkedstack_peek(SListEntry *linkedStack);

/* 判断栈是否为空 */
int linkedstack_is_empty(SListEntry *linkedStack);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef ALGORITHM_LINKEDSTACK_H */

