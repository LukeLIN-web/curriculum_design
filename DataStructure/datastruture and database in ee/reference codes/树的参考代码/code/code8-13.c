#include "seqstack.h"
void bitree_nrpost_order(BiTreeNode *node){
	ArrayList *stack = seqstack_new(MAXNODE);
	BiTreeNode *p;
	stacktype *q;
	int sign;
	if(tree == NULL)
		return;
	while(!(p == NULL && seqstack_is_empty(stack))) {
		if(p != NULL) {	/* 节点第一次进栈 */
			q = malloc(sizeof(stacktype));
			q->link = p;
			q->flag = 1;
			seqstack_push(stack, q);
			p = p->children[BITREE_NODE_LEFT];
		}
		else {
			p = seqstack_peek(stack)->link;
			sign = seqstack_peek(stack)->flag;
			seqstack_pop(stack);
			if(sign == 1) {
				q = malloc(sizeof(stacktype));
				q->link = p;
				q->flag = 2;
				seqstack_push(stack, q);
				p = p->children[BITREE_NODE_RIGHT];
			}
			else {
				(*visit)(p);
				p = NULL;
			}
		} 
	}
}