typedef struct _AVLTree AVLTree;	/* 二叉平衡树结构 */
typedef void *AVLTreeKey;	/* 二叉平衡树的关键字 */
typedef void *AVLTreeValue;	/* 二叉平衡树中存储的数据 */
#define AVLTREE_NULL ((void *) 0)	/* 二叉平衡树的空指针数据 */
typedef struct _AVLTreeNode AVLTreeNode;	/* 二叉平衡树节点 */
/* 二叉平衡树的左、右孩子标记 */
typedef enum {
    AVLTREE_NODE_LEFT = 0,
    AVLTREE_NODE_RIGHT = 1
} AVLTreeNodeSide;

/* 比较二叉平衡树关键字的函数 */
typedef int (*AVLTreeCompareFunc)(AVLTreeValue value1, AVLTreeValue value2);

struct _AVLTreeNode {
    AVLTreeNode *children[2];
    AVLTreeNode *parent;
    AVLTreeKey key;
    AVLTreeValue value;
    int height;
};

struct _AVLTree {
    AVLTreeNode *root_node;
    AVLTreeCompareFunc compare_func;
    unsigned int num_nodes;
};