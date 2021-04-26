/* 二叉树的左、右孩子标记 */
typedef enum {	
    BITREE_NODE_LEFT = 0,
    BITREE_NODE_RIGHT = 1
} BiTreeNodeSide;
typedef struct _BiTree BiTree;	/* 二叉树结构 */
typedef struct _BiTreeNode BiTreeNode;	/* 二叉树节点 */
typedef void *BiTreeValue;	/* 二叉树中存储的数据 */
#define BITREE_NULL ((void *) 0)	/* 二叉树的空指针数据 */

struct _BiTreeNode {
    BiTreeNode *children[2];
    BiTreeNode *parent;
    BiTreeValue value;
};

struct _BiTree {
    BiTreeNode *rootnode;	/* 根节点 */
    unsigned int nodenum;	/* 节点数 */
};