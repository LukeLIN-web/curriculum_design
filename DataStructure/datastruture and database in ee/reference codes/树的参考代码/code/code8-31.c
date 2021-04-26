static void avltree_update_height(AVLTreeNode *node) {
    AVLTreeNode *left_subtree;
    AVLTreeNode *right_subtree;
    int left_height, right_height;
    left_subtree = node->children[AVLTREE_NODE_LEFT];
    right_subtree = node->children[AVLTREE_NODE_RIGHT];
    left_height = avltree_subtree_height(left_subtree);
    right_height = avltree_subtree_height(right_subtree);
    if (left_height > right_height)
        node->height = left_height + 1;
    else
        node->height = right_height + 1;
}