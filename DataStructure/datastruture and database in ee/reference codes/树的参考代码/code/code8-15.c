void bitree_remove_subtree(BiTree *tree, BiTreeNode *node) {
    if (node == NULL)
        return;
    bitree_remove_subtree(tree, node->children[BITREE_NODE_LEFT]);
    bitree_remove_subtree(tree, node->children[BITREE_NODE_RIGHT]);
    free(node);
    tree->nodenum--;
}

void bitree_free(BiTree *tree) {
    bitree_free_subtree(tree->rootnode);	/* 销毁所有的节点 */
    free(tree);		
}

void bitree_remove(BiTree *tree, BiTreeNode *node) {
    BiTreeNode *parent = node->parent;
    if(parent != NULL)
        if(parent->children[BITREE_NODE_LEFT] == node)
            parent->children[BITREE_NODE_LEFT] = NULL;
        else if(parent->children[BITREE_NODE_RIGHT] == node)
            parent->children[BITREE_NODE_RIGHT] = NULL;      
    else /*这是根节点*/
        tree->rootnode = NULL;
    bitree_remove_subtree(tree, node);
}

BiTreeNode *bitree_rootnode(BiTree *tree) {
    return tree->rootnode;
}

BiTreeValue bitree_node_value(BiTreeNode *node) {
    return node->value;
}

BiTreeNode *bitree_node_child(BiTreeNode *node, BiTreeNodeSide side) {
    if (side == BITREE_NODE_LEFT || side == BITREE_NODE_RIGHT)
        return node->children[side];
    else
        return NULL;
}

BiTreeNode *bitree_node_parent(BiTreeNode *node) {
    return node->parent;
}

BiTree * bitree_new() {
    BiTree *newtree;
    newtree = (BiTree *) malloc(sizeof(BiTree));
    if (newtree == NULL)
        return NULL;
    newtree->rootnode = NULL;
    newtree->nodenum = 0;
    return newtree;
}