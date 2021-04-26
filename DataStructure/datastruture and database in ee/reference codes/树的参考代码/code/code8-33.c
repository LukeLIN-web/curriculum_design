AVLTreeNode *avltree_insert(AVLTree *tree, AVLTreeKey key, AVLTreeValue value) {
    AVLTreeNode **rover;
    AVLTreeNode *new_node;
    AVLTreeNode *previous_node;
	/* 遍历二叉平衡树，一直到空指针处 */
    rover = &tree->root_node;
    previous_node = NULL;
    while (*rover != NULL) {
        previous_node = *rover;
        if (tree->compare_func(key, (*rover)->key) < 0)
            rover = &((*rover)->children[AVLTREE_NODE_LEFT]); 
		else
            rover = &((*rover)->children[AVLTREE_NODE_RIGHT]);
    }
	/* 创建一个新节点，以遍历的路径上最后一个节点为双亲节点 */
    new_node = (AVLTreeNode *) malloc(sizeof(AVLTreeNode));
    if (new_node == NULL)
        return NULL;
    new_node->children[AVLTREE_NODE_LEFT] = NULL;
    new_node->children[AVLTREE_NODE_RIGHT] = NULL;
    new_node->parent = previous_node;
    new_node->key = key;
    new_node->value = value;
    new_node->height = 1;
    *rover = new_node;	/* 在遍历到达的空指针处插入节点 */
    avltree_balance_to_root(tree, previous_node);	/* 使树重新平衡 */
    ++tree->num_nodes;	/* 更新节点数 */
    return new_node;
}