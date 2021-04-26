/* 删除树中的一棵子树 */
void bitree_remove_subtree(BiTree *tree, BiTreeNode *node);

/* 销毁一棵二叉树 */
void bitree_free(BiTree *tree);

/* 给定双亲节点和左右的位置，插入一个节点 */
BiTreeNode * bitree_insert(BiTree *tree, BiTreeValue value,
							BiTreeNode *parent, BiTreeNodeSide side);

/* 删除一个节点 */
void bitree_remove(BiTree *tree, BiTreeNode *node);

/* 查找二叉树的根节点 */
BiTreeNode *bitree_rootnode(BiTree *tree);
	
/* 获取给定节点中的数据 */
BiTreeValue bitree_node_value(BiTreeNode *node);

/* 查找给定节点的孩子节点 */
BiTreeNode *bitree_node_child(BiTreeNode *node, BiTreeNodeSide side);

/* 查找给定节点的双亲节点 */
BiTreeNode *bitree_node_parent(BiTreeNode *node);

/* 建立一棵新的二叉树 */
BiTree * bitree_new();