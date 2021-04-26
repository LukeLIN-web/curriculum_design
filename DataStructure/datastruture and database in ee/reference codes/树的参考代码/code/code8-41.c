BiTreeNode *bitree_insert(BiTree *tree, BiTreeValue value,
							BiTreeNode *parent, BiTreeNodeSide side) {
    BiTreeNode * newnode;
    if((newnode = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
        return NULL;
    //初始化
    newnode->children[BITREE_NODE_LEFT] = NULL;
    newnode->children[BITREE_NODE_RIGHT] = NULL;
    newnode->value = value;
    newnode->parent = parent;
    if(parent == NULL) {
		//插入根节点
        if(tree->rootnode != NULL)
            tree->rootnode->parent = newnode;
        newnode->children[side] = tree->rootnode;
        tree->rootnode = newnode;
    } 
	else {
        if(parent->children[side] != NULL)
            parent->children[side]->parent = newnode;
        newnode->children[side] = parent->children[side];
        parent->children[side] = newnode;
    }
    tree->nodenum++;
    return newnode;
}