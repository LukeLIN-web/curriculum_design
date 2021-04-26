typedef struct _RBTree RBTree;	/* 红黑树结构 */
typedef void *RBTreeKey;	/* 关键字 */
typedef void *RBTreeValue;	/* 红黑树中存储的数据 */
#define RBTREE_NULL ((void *) 0)	/* 红黑树的空指针数据 */
typedef struct _RBTreeNode RBTreeNode;	/* 红黑树节点 */
/* 比较红黑树关键字的函数 */
typedef int (*RBTreeCompareFunc)(RBTreeValue data1, RBTreeValue data2);
/* 红黑树节点的红黑颜色标记 */
typedef enum {
	RBTREE_NODE_RED,
	RBTREE_NODE_BLACK,
} RBTreeNodeColor;
/* 红黑树的左、右孩子标记 */
typedef enum {
	RBTREE_NODE_LEFT = 0,
	RBTREE_NODE_RIGHT = 1
} RBTreeNodeSide;

struct _RBTreeNode {
	RBTreeNodeColor color;
	RBTreeKey key;
	RBTreeValue value;
	RBTreeNode *parent;
	RBTreeNode *children[2];
};
struct _RBTree {
	RBTreeNode *root_node;
	RBTreeCompareFunc compare_func;
	int num_nodes;
};