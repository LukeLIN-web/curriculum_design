RBTreeNode *rbtree_insert(RBTree *tree, RBTreeKey key, RBTreeValue value) {
	RBTreeNode *node;
	RBTreeNode **rover;
	RBTreeNode *parent;
	RBTreeNodeSide side;
	node = malloc(sizeof(RBTreeNode));
	if (node == NULL)
		return NULL;
	/* 初始化新节点。涂成红色 */
	node->key = key;
	node->value = value;
	node->color = RBTREE_NODE_RED;
	node->children[RBTREE_NODE_LEFT] = NULL;
	node->children[RBTREE_NODE_RIGHT] = NULL;
	/* 首先进行正常的二叉平衡树插入操作 */
	parent = NULL;
	rover = &tree->root_node;
	while (*rover != NULL) {
		parent = *rover;	/* 更新父节点指针 */
		if (tree->compare_func(value, (*rover)->value) < 0) 
			side = RBTREE_NODE_LEFT;
		else
			side = RBTREE_NODE_RIGHT;
		rover = &(*rover)->children[side];
	}
	/* 插入节点 */
	*rover = node;
	node->parent = parent;
	rbtree_insert_case1(tree, node);	/* 调整树以满足红黑树性质 */
	++tree->num_nodes;	/* 更新节点数 */
	return node;
}