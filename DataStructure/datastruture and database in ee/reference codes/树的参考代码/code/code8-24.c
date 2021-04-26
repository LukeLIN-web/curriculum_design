/* 在二叉查找树中插入一个节点 */
BsTreeNode *bstree_insert(BsTree *tree, BsTreeKey key, BiTreeValue value);

/* 删除一个给定的节点 */
void bstree_remove_node(BsTree *tree, BsTreeNode *node);

/* 给定关键字，删除节点 */
int bstree_remove_by_key(BsTree *_this, BsTreeKey key);

/* 查找二叉查找树子树中最小元 */
BsTreeNode *bstree_find_min(BsTreeNode *node);

/* 查找二叉查找树子树中最大元 */
BsTreeNode *bstree_find_max(BsTreeNode *node);

/* 给定关键字，查找节点并返回该节点的指针 */
BsTreeNode *bstree_lookup_node(BsTree *_this, BsTreeKey key);

/* 给定关键字，查找节点并返回节点中的数据 */
BiTreeValue bstree_lookup(BsTree *_this, BsTreeKey key);

/* 建立一棵新的二叉查找树 */
BsTree *bstree_new(BsTreeCompareFunc compareFunc);