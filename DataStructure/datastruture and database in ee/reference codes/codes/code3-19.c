/* 返回x在表list中的位置，如果没找到x返回0 */
/* 使用头结点 */
Position find(ElementType x, List list){
	Position position;
	
	position = cursor_space[list].next;
	while (position && cursor_space[position].element != x)
		position = cursor_space[position].next;
	
	return position;
}