BsTreeNode *bstree_lookup_node(BsTree *tree, BsTreeKey key) {
    BsTreeNode *node;
    int diff;
	/* 搜索二叉查找树并且寻找含有特定关键字的节点 */
    node = tree->base.rootnode;
    while (node != NULL) {
        diff = tree->compareFunc(key, node->key);
        if (diff == 0) 
            return node;	/* 关键字相同则返回 */
		else if (diff < 0)
            node = node->base.children[BITREE_NODE_LEFT];
		else
            node = node->base.children[BITREE_NODE_RIGHT];
    }
    return NULL;	/* 未找到 */
}