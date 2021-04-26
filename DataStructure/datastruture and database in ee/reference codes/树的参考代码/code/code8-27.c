BsTreeNode *bstree_find_max(BsTreeNode *node) {
	if(node == NULL)
		return NULL;
	else
		if(node->base.children[BITREE_NODE_RIGHT] == NULL)
			return node;
		else
			return bstree_find_max(node->base.children[BITREE_NODE_RIGHT]);
}