int bstree_remove_by_key(BsTree *_this, BsTreeKey key) {
	BsTreeNode *node, *tmpcell; 
	node = bstree_lookup_node(_this, key);
	int keyvalue;
	if(node != NULL) {
		/* 两个孩子节点 */
		if(node->base.children[BITREE_NODE_LEFT] != NULL &&
				node->base.children[BITREE_NODE_RIGHT] != NULL) {
			/* 用右子树的最小节点替换 */
			tmpcell = bstree_find_min(node->base.children[BITREE_NODE_RIGHT]);
			keyvalue = *((int *)tmpcell->key);
			bstree_remove_by_key (_this, tmpcell->key);
			node->key = &keyvalue;
		} else {	/* 有一个或无孩子节点 */
			if(node->base.children[BITREE_NODE_LEFT] == NULL) {
				/* 判断node是左孩子还是右孩子节点指针 */
				if(int_compare(((BsTreeNode *)node->base.parent)->key, node->key))
					node->base.parent->children[BITREE_NODE_LEFT] = node->base.children[BITREE_NODE_RIGHT];
				else
					node->base.parent->children[BITREE_NODE_RIGHT] = node->base.children[BITREE_NODE_RIGHT];
			} else if(node->base.children[BITREE_NODE_RIGHT] == NULL) {
				if(int_compare(((BsTreeNode *)node->base.parent)->key, node->key))
					node->base.parent->children[BITREE_NODE_LEFT] = node->base.children[BITREE_NODE_LEFT];
				else
					node->base.parent->children[BITREE_NODE_RIGHT] = node->base.children[BITREE_NODE_LEFT];
			}
			free(node);
		}
		return 1;
	}
    return 0;
}