BsTreeNode *bstree_insert(BsTree *tree, BsTreeKey key, BiTreeValue value) {
    BsTreeNode **rover;
    BsTreeNode *newnode;
    BsTreeNode *previousnode;   
	/* 遍历二叉查找树，一直到空指针处 */
    rover = &(((BiTree *)tree)->rootnode);
    previousnode = NULL;
    while (*rover != NULL) {
        previousnode = *rover;
        if (tree->compareFunc(key, (*rover)->key) < 0)
            rover = &((*rover)->base.children[BITREE_NODE_LEFT]);
		else
            rover = &((*rover)->base.children[BITREE_NODE_RIGHT]);
    }
	/* 创建一个新节点，以遍历的路径上最后一个节点为双亲节点 */
    newnode = (BsTreeNode *)malloc(sizeof(BsTreeNode));
    if (newnode == NULL)
        return NULL;
    newnode->base.children[BITREE_NODE_LEFT] = NULL;
    newnode->base.children[BITREE_NODE_RIGHT] = NULL;
    newnode->base.parent = previousnode;
    newnode->base.value = value;
    newnode->key = key;
    *rover = newnode;	/* 在遍历到达的空指针处插入节点 */
    ++tree->base.nodenum;	/* 更新节点数 */
    return newnode;
}