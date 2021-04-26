static AVLTreeNode *avltree_node_balance(AVLTree *tree, AVLTreeNode *node) {
    AVLTreeNode *left_subtree;
    AVLTreeNode *right_subtree;
    AVLTreeNode *child;
    int diff;
    left_subtree = node->children[AVLTREE_NODE_LEFT];
    right_subtree = node->children[AVLTREE_NODE_RIGHT];
	/* 检查孩子节点的高度。如果不平衡，则旋转 */
    diff = avltree_subtree_height(right_subtree)
         - avltree_subtree_height(left_subtree);
    if (diff >= 2) {	/* 偏向右侧太多 */
        child = right_subtree;
        if (avltree_subtree_height(child->children[AVLTREE_NODE_RIGHT])
          < avltree_subtree_height(child->children[AVLTREE_NODE_LEFT])) {
			/* 如果右孩子偏向左侧，它需要首先右旋转（双旋转） */
            avltree_rotate(tree, right_subtree, AVLTREE_NODE_RIGHT);
        }
        node = avltree_rotate(tree, node, AVLTREE_NODE_LEFT);	/* 进行左旋转 */
    } 
	else if (diff <= -2) {	/* 偏向左侧太多 */
        child = node->children[AVLTREE_NODE_LEFT];
        if (avltree_subtree_height(child->children[AVLTREE_NODE_LEFT])
          < avltree_subtree_height(child->children[AVLTREE_NODE_RIGHT])) {
			/* 如果左孩子偏向右侧，它需要首先左旋转（双旋转） */
            avltree_rotate(tree, left_subtree, AVLTREE_NODE_LEFT);
        }
        node = avltree_rotate(tree, node, AVLTREE_NODE_RIGHT);	/* 进行右旋转 */
    }
    avltree_update_height(node);	/* 更新节点的高度 */
    return node;
}