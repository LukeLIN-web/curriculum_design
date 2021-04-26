/* visit是访问节点的函数指针 */
void bitree_pre_order(BiTreeNode *node, BitreeValue (*visit)(BiTreeNode *)) {
	if(node) {
		(*visit)(node);	/* 访问节点 */
		/* 前序遍历左子树 */
        if(bitree_pre_order(node->children[BITREE_NODE_LEFT], visit)) {
            /* 前序遍历右子树 */ 
            if(bitree_pre_order(node->children[BITREE_NODE_RIGHT], visit))
				return 1;
        return 0;
    	}
    }
    return 1;
}