typedef struct _Tree Tree;	/* 树结构 */
typedef struct _TreeNode TreeNode;	/* 树的节点 */
typedef void *TreeValue;	/* 树中存储的数据 */ 
#define TREE_NULL ((void *) 0)	/* 树的空指针数据 */
 
struct TreeNode {
	TreeValue value;
	TreeNode *firstchild;
	TreeNode *nextsibling;
};

struct _Tree {
	TreeNode *rootnode;
	unsigned int nodenum;
};