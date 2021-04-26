void bitree_post_order(BiTreeNode *node, BitreeValue(*visit)(BiTreeNode *)) {
	if(node) {
		/* 后序遍历左子树 */
        if(bitree_post_order(node->children[BITREE_NODE_LEFT], visit)) {
            /* 后序遍历右子树 */ 
            if(bitree_post_order(node->children[BITREE_NODE_RIGHT], visit)) { 
            	(*visit)(node);	/* 访问节点 */
				return 1;
			}
            return 0;
        }
        return 0;
    }
    return 1; 
}