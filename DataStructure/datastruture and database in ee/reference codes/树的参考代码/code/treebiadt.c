biTree_init(&T)；
操作结果：构造空二叉树T。

biTree_destroy(&T)；
初始条件：二叉树T存在。
操作结果：销毁空二叉树T。

biTree_create(&T,definition)；
初始条件：definition给出二叉树T的定义。
操作结果：按definition构造二叉树T。

biTree_clear(&T)；
初始条件：二叉树T存在。
操作结果：将二叉树T清空为树。

biTree_empty(T)；
初始条件：二叉树T存在。
操作结果：若T为空二叉树，则返回TRUE，否则FALSE。

biTree_depth(T)；
初始条件：二叉树T存在。
操作结果：返回T的深度。

biTree_root(T)；
初始条件：二叉树T存在。
操作结果：返回T的根。

biTree_value(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：返回e的值。

biTree_assign(T,&e,value)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：节点e赋值为value。

biTree_parent(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：若e是T的非根节点，则返回它的双亲，否则返回“空”。

biTree_left_child(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：返回e的左孩子。若e无左孩子，则返回“空”。

biTree_right_child(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：返回e的右孩子。若e无右孩子，则返回“空”。

biTree_left_sibling(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空”。

biTree_right_sibling(T,e)；
初始条件：二叉树T存在，e是T中某个节点。
操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回“空”。

biTree_insert_child(T,p,LR,c)；
初始条件：二叉树T存在，p指向T中某个节点，LR为0或1，非空二叉树c与T不相交且右子树为空。
操作结果：根据LR为0或1，插入c为T中p所指节点的左或右子树。p所指向节点的原有左或右子树则成为c的右子树。

biTree_delete_child(T,p,LR)；
初始条件：二叉树T存在，p指向T中某个节点，LR为0或1。
操作结果：根据LR为0或1，删除T中p所指节点的左或右子树。

biTree_pre_order_traverse(T,visit())；
初始条件：二叉树T存在，visit是对节点操作的应用函数。
操作结果：前序遍历T，对每个节点调用函数visit一次且仅一次。一旦visit()失败，则操作失败。

biTree_in_order_traverse(T,visit())；
初始条件：二叉树T存在，visit是对节点操作的应用函数。
操作结果：中序遍历T，对每个节点调用函数visit一次且仅一次。一旦visit()失败，则操作失败。

biTree_post_order_traverse(T,visit())；
初始条件：二叉树T存在，visit是对节点操作的应用函数。
操作结果：后序遍历T，对每个节点调用函数visit一次且仅一次。一旦visit()失败，则操作失败。

biTree_level_order_traverse(T,visit())；
初始条件：二叉树T存在，visit是对节点操作的应用函数。
操作结果：层序遍历T，对每个节点调用函数visit一次且仅一次。一旦visit()失败，则操作失败。