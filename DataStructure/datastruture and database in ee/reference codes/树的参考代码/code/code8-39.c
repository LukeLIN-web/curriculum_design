/* 单旋转。node是待旋转子树的根节点，direction是旋转的方向 */
static RBTreeNode *rbtree_rotate(RBTree *tree, RBTreeNode *node,
                                  RBTreeNodeSide direction) {
	RBTreeNode *new_root;
	/* 根节点的孩子节点将取代其位置：左旋转则右孩子取代，反之左孩子取代 */
	new_root = node->children[1-direction];
	rbtree_node_replace(tree, node, new_root);
	/* 重置指针变量 */
	node->children[1-direction] = new_root->children[direction];
	new_root->children[direction] = node;
	/* 更新双亲节点 */
	node->parent = new_root;
	if (node->children[1-direction] != NULL)
		node->children[1-direction]->parent = node;
	return new_root;
}

/* 将节点1用节点2替换 */
static void rbtree_node_replace(RBTree *tree, RBTreeNode *node1, RBTreeNode *node2) {
	int side;
	if (node2 != NULL)	
		node2->parent = node1->parent;	/* 设置节点的双亲指针 */
	if (node1->parent == NULL)
		tree->root_node = node2;
	else {
		side = rbtree_node_side(node1);
		node1->parent->children[side] = node2;
	}
}