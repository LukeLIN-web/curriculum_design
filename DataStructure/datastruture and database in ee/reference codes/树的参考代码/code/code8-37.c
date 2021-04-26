void print_tree(RBTreeNode *node, int depth) {
	int *value, i;
	if (node == NULL)
		return;
	print_tree(rbtree_node_child(node, RBTREE_NODE_LEFT), depth + 1);
	for (i=0; i<depth*6; ++i)
		printf(" ");
	value = rbtree_node_key(node);
	printf("%i\n", *value);
	print_tree(rbtree_node_child(node, RBTREE_NODE_RIGHT), depth + 1);
}