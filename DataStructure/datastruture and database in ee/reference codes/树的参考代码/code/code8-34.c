/* 单旋转。node是待旋转子树的根节点，direction是旋转的方向 */
static AVLTreeNode *avltree_rotate(AVLTree *tree, AVLTreeNode *node,
                                    AVLTreeNodeSide direction) {
    AVLTreeNode *new_root;
	/* 根节点的孩子节点将取代其位置：左旋转则右孩子取代，反之左孩子取代 */
    new_root = node->children[1-direction];
    avltree_node_replace(tree, node, new_root);
    /* 重置指针变量 */
    node->children[1-direction] = new_root->children[direction];
    new_root->children[direction] = node;
	/* 更新双亲节点 */
    node->parent = new_root;	
    if (node->children[1-direction] != NULL)
        node->children[1-direction]->parent = node;
    /* 更新节点的高度 */
    avltree_update_height(new_root);
    avltree_update_height(node);
    return new_root;
}