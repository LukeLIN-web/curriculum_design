/* 删除表中出现的第一个x */
/* 假定使用了头结点 */
void delete_element(ElementType x, List list){
	Position position, tmpcell;
	
	position = find_previous(x, list);
	
	if (!is_last(position, list)) {	/* X被找到，删除该结点 */
		tmpcell = cursor_space[position].next;
		cursor_space[position].next = cursor_space[tmpcell].next;
		cursor_free(tmpcell);
	}
} 