typedef void *BsTreeKey;	/* 二叉查找树的关键字 */
typedef struct _BsTree BsTree;	/* 二叉查找树 */
typedef struct _BsTreeNode BsTreeNode;	/* 二叉查找树节点 */

struct _BsTreeNode {
    struct _BiTreeNode base;
    BsTreeKey key;
};

/* 比较二叉查找树关键字的函数 */
typedef int (*BsTreeCompareFunc)(BiTreeValue value1, BiTreeValue value2);

struct _BsTree {
    struct _BiTree base;	/* 以二叉树为基本结构 */
    BsTreeCompareFunc compareFunc;	/* 查找时比较两个key时用的函数 */
};