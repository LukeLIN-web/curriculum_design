/* 在合法的结点position之后插入 */
/* 假定使用带头结点的表 */
/* 在这种实现里参数list未被使用 */
void insert(ElementType x, List list, Position position){
	Position tmpcell;
	
	tmpcell = cursor_alloc();
	if(tmpcell == 0)
		FatalError("Out of Space!");
	
	cursor_space[tmpcell].element = x;
	cursor_space[tmpcell].next = cursor_space[position].next;
	cursor_space[position].next = tmpcell;
}