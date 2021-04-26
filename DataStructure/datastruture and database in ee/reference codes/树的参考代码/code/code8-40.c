/* 插入情形1：新节点是根节点，则它必须涂成黑色 */
static void rbtree_insert_case1(RBTree *tree, RBTreeNode *node) {
	if (node->parent == NULL)
		node->color = RBTREE_NODE_BLACK;	/* 根节点是黑色的 */
	else	/* 不是根节点 */
		rbtree_insert_case2(tree, node);	
}

/* 插入情形2：新节点的父节点是红色的 */
static void rbtree_insert_case2(RBTree *tree, RBTreeNode *node) {
	/* 当调用这个函数的时候，已经保证了插入的节点不是根节点 */
	if (node->parent->color != RBTREE_NODE_BLACK)
		rbtree_insert_case3(tree, node);
}

/* 插入情形3：如果父节点及其兄弟节点都是红色的 */
static void rbtree_insert_case3(RBTree *tree, RBTreeNode *node) {
	RBTreeNode *grandparent;
	RBTreeNode *uncle;
	/* 因为父节点是红色的，所以插入的节点一定存在祖父节点 */
	grandparent = node->parent->parent;
	uncle = rbtree_node_uncle(node);
	if (uncle != NULL && uncle->color == RBTREE_NODE_RED) {
		node->parent->color = RBTREE_NODE_BLACK;
		uncle->color = RBTREE_NODE_BLACK;
		grandparent->color = RBTREE_NODE_RED;
		/* 递归上滤直到不再有两个相连的红色节点或到达根处 */
		rbtree_insert_case1(tree, grandparent);	
	} 
	else
		rbtree_insert_case4(tree, node);
}

/* 插入情形4：父节点是红色的，父节点的兄弟节点是黑色的 */
void rbtree_insert_case4(RBTree *tree, RBTreeNode *node) {
	RBTreeNode *next_node;
	RBTreeNodeSide side;
	side = rbtree_node_side(node);
	if (side != rbtree_node_side(node->parent)) {
		/* 需要进行双旋转。这里旋转一次后成为情形5 */
		next_node = node->parent;
		rbtree_rotate(tree, node->parent, 1-side);	/* 按插入节点的左右方向的相反方向旋转父节点 */
	} 
	else
		next_node = node;
	rbtree_insert_case5(tree, next_node);
}

/* 插入情形5：插入的节点及其父节点作为作为孩子节点的左右方向相同，都为红色，父节点的兄弟节点为黑色 */
void rbtree_insert_case5(RBTree *tree, RBTreeNode *node) {
	RBTreeNode *parent;
	RBTreeNode *grandparent;
	RBTreeNodeSide side;
	parent = node->parent;
	grandparent = parent->parent;
	side = rbtree_node_side(node);	/* 插入节点的左右方向 */
	rbtree_rotate(tree, grandparent, 1-side);	/* 按相反方向旋转祖父节点 */
	/* 重新着色 */
	parent->color = RBTREE_NODE_BLACK;
	grandparent->color = RBTREE_NODE_RED;
}