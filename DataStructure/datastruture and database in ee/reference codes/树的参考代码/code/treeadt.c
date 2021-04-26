tree_init(&T)；
操作结果：构造空树T。

tree_destroy(&T)；
初始条件：树T存在。
操作结果：销毁树T。

tree_create(&T,definition)；
初始条件：definition给出树T的定义。
操作结果：按definition构造树T。

tree_clear(&T)；
初始条件：树T存在。
操作结果：将树T清为空树。

tree_empty(T)；
初始条件：树T存在。
操作结果：若树T为空树，则返回TRUE，否则FALSE。

tree_depth(T)；
初始条件：树T存在。
操作结果：返回T的深度。

tree_root(T)；
初始条件：树T存在。
操作结果：返回T的根。

tree_value(T,cur_e)；
初始条件：树T存在，cur_e是T中某个节点。
操作结果：返回cur_e的值。

tree_assign(T,cur_e,value)；
初始条件：树T存在，cur_e是T中某个节点。
操作结果：节点cur_e赋值为value。

tree_parent(T,cur_e)；
初始条件：树T存在，ccur_e是T中某个节点。
操作结果：若cur_e是T的非根节点，则返回它的双亲，否则函数值为“空”。

tree_left_child(T,cur_e)；
初始条件：树T存在，cur_e是T中某个节点。
操作结果：若cur_e是T的非叶子节点，则返回它的最左孩子，否则返回“空”。

tree_right_sibling(T,cur_e)；
初始条件：树T存在，cur_e是T中某个节点。
操作结果：若cur_e有右兄弟，则返回它的右兄弟，否则函数值为“空”。

tree_insert_child(&T,&p,i,c)；
初始条件：树T存在，p指向T中某个节点，1≤ i≤ p所指节点的度+1，非空树c与T不相交。
操作结果：插入c为T中p指节点的第i棵子树。

tree_delete_child(&T,&p,i)；
初始条件：树T存在，p指向T中某个节点，1≤ i≤ p所指节点的度。
操作结果：删除T中p指节点的第i棵子树。

tree_traverse(T,visit())；
初始条件：树T存在，Visit是对节点操作的应用函数。
操作结果：按某种次序对T的每个节点调用函数visit()一次且至多一次。一旦visit()失败，则操作失败。