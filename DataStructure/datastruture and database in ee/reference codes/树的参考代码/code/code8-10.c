#include "seqqueue.h"
void bitree_level_order(BiTreeNode *node, BitreeValue(*visit)(BiTreeNode *)) {
	Queue *queue = new_queue();
	if(node == NULL)
		return;
	while(!queue_is_empty(queue)) {
		visit(queue->array[0]);	/* 访问队首节点 */
		queue_pop_head(queue);
		if(queue->array[0]->children[BITREE_NODE_LEFT] != NULL)
			/* 将队首节点的左孩子节点入队列 */
			queue_push_tail(queue, queue->array[0]->children[BITREE_NODE_LEFT]);
		if(queue->array[0]->children[BITREE_NODE_RIGHT] != NULL)
			/* 将队首节点的右孩子节点入队列 */
			queue_push_tail(queue, queue->array[0]->children[BITREE_NODE_RIGHT]);
		queue_push_tail(queue, node);
	}
}