static Position cursor_alloc(void){
	Position position;
	position = cursor_space[0].Next;
	CursorSpace[0].Next = cursor_space[position].Next;

	return position;
}

static void cursor_free(Position position){
	cursor_space[position].next = cursor_space[0].next;
	cursor_space[0].Next = position;
}