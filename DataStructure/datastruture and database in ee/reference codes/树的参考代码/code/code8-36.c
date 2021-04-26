void avltree_remove_node(AVLTree *tree, AVLTreeNode *node) {
    AVLTreeNode *swap_node;
    AVLTreeNode *balance_startpoint;
    int i;
	/* 待删除的节点需要用关键字与其最接近的节点取代其位置，找到交换的节点 */
    swap_node = avltree_node_get_replacement(tree, node);
    if (swap_node == NULL) {
		/* 这是一个叶子节点，可以直接删除 */
        avltree_node_replace(tree, node, NULL);	/* 将节点与其双亲断开 */	
        balance_startpoint = node->parent;	/* 从原节点的双亲开始重新平衡 */
    } 
	else {
		/* 从交换的节点的原双亲开始重新平衡。当原双亲是待删除节点时，从交换的节点开始重新平衡 */
        if (swap_node->parent == node)
            balance_startpoint = swap_node; 
		else
            balance_startpoint = swap_node->parent;
		/* 将与原节点相关的指针引用复制到交换的节点中 */
        for (i=0; i<2; ++i) {
            swap_node->children[i] = node->children[i];
            if (swap_node->children[i] != NULL)
                swap_node->children[i]->parent = swap_node;
        }
        swap_node->height = node->height;
        avltree_node_replace(tree, node, swap_node);
    }
    free(node);
    --tree->num_nodes;	/* 更新节点数 */
    avltree_balance_to_root(tree, balance_startpoint);	/* 使树重新平衡 */
}