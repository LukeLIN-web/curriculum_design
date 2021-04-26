#include "seqstack.h"
void bitree_nrpre_order(BiTreeNode *node, BitreeValue(*visit)(BiTreeNode *)) {
	ArrayList *stack = seqstack_new(MAXNODE);
	BiTreeNode *p;
	if(node == NULL)
		return;
	p = node;
	while(!(p == NULL && seqstack_is_empty(stack))) {
		while(p != NULL) {
			(*visit)(p);	/* 访问节点 */
			seqstack_push(stack, p);
			p = p->children[BITREE_NODE_LEFT];
		}
		if(seqstack_is_empty(stack))	/* 栈空时结束 */
			return;
		else {
			p = (BiTreeNode *)seqstack_pop(stack);
			p = p->children[BITREE_NODE_RIGHT];
		} 
	}
}