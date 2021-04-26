/* 找出节点连在其双亲节点的哪一侧 */
static AVLTreeNodeSide avltree_node_parent_side(AVLTreeNode *node) {
    if (node->parent->children[AVLTREE_NODE_LEFT] == node)
        return AVLTREE_NODE_LEFT;
    else
        return AVLTREE_NODE_RIGHT;
}

/* 将节点1用节点2替换 */
static void avltree_node_replace(AVLTree *tree, AVLTreeNode *node1,
                                  AVLTreeNode *node2) {
    int side;
    if (node2 != NULL)
        node2->parent = node1->parent;	/* 设置节点的双亲指针 */
    if (node1->parent == NULL)
        tree->root_node = node2;
    else {
        side = avltree_node_parent_side(node1);
        node1->parent->children[side] = node2;
        avltree_update_height(node1->parent);
    }
}

/* 找到与给定节点关键字最接近的节点，将其从树中断开 */
static AVLTreeNode *avltree_node_get_replacement(AVLTree *tree,
                                                  AVLTreeNode *node) {
    AVLTreeNode *left_subtree;
    AVLTreeNode *right_subtree;
    AVLTreeNode *result;
    AVLTreeNode *child;
    int left_height, right_height;
    int side;
    left_subtree = node->children[AVLTREE_NODE_LEFT];
    right_subtree = node->children[AVLTREE_NODE_RIGHT];
    if (left_subtree == NULL && right_subtree == NULL)	/* 无孩子节点 */
        return NULL;
	/* 从更高的子树中选择节点，以使树保持平衡 */
    left_height = avltree_subtree_height(left_subtree);
    right_height = avltree_subtree_height(right_subtree);
    if (left_height < right_height)
        side = AVLTREE_NODE_RIGHT;
    else
        side = AVLTREE_NODE_LEFT;
	/* 搜索关键字最接近的节点 */
    result = node->children[side];
    while (result->children[1-side] != NULL)
        result = result->children[1-side];
	/* 断开节点，如果它有孩子节点则取代其位置 */
    child = result->children[side];
    avltree_node_replace(tree, result, child);
    avltree_update_height(result->parent);
    return result;
}