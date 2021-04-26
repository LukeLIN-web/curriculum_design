int bitree_in_order(BiTreeNode *node, BitreeValue(*visit)(BiTreeNode *)) {
	if(node) {
		/* 中序遍历左子树 */
        if(bitree_in_order(node->children[BITREE_NODE_LEFT], visit)) {
            (*visit)(node);	/* 访问节点 */
            /* 中序遍历右子树 */ 
            if(bitree_in_order(node->children[BITREE_NODE_RIGHT], visit))
				return 1;
            return 0;
        }
        return 0;
    }
    return 1;
}