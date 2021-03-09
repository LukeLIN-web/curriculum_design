/* 如果position是表list的最后一个结点返回1 */
/* 在这种实现里参数list未被使用 */
int is_last(Position position, List list){
	return cursor_space[position].next == 0;
} 