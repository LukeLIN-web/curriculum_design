#ifndef ALGORITHM_SEQSTACK_H
#define ALGORITHM_SEQSTACK_H
#ifdef __cplusplus
extern "C" {
#endif
#include "arraylist.h"

/* 建立一个新的栈 */
ArrayList *seqstack_new(unsigned int length);

/* 销毁一个栈 */
void seqstack_free(ArrayList *seqstack);

/* 在栈顶插入元素 */
int seqstack_push(ArrayList *seqstack, ArrayListValue data);

/* 从栈中删除栈顶元素 */
ArrayListValue seqstack_pop(ArrayList *seqstack);

/* 读取栈顶元素 */
ArrayListValue seqstack_peek(ArrayList *seqstack);

/* 判断栈是否为空 */
int seqstack_is_empty(ArrayList *seqstack);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef ALGORITHM_SEQSTACK_H */

