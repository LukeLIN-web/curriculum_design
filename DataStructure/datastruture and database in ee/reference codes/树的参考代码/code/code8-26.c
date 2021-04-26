BsTreeNode *bstree_find_min(BsTreeNode *node) {
	if(node != NULL)
		while(node->base.children[BITREE_NODE_LEFT] != NULL) 
			node = node->base.children[BITREE_NODE_LEFT];
	return node;
}