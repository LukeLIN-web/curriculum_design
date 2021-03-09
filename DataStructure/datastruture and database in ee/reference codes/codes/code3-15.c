#ifndef _Cursor_H

typedef int ptr_to_node;
typedef ptr_to_node List;
typedef ptr_to_node Position;

void initialize_cursor_space(void);

List make_empty(List list);
int is_empty(const List list);
int is_last(const Position position, const List list);
Position find(ElementType x, const List list);
void delete_element(ElementType x, List list);
Position find_previous(ElementType x, const List list);
void insert(ElementType x, List list, Position position);
void delete_list(List list);
Position header(const List list);
Position first(const List list);
Position advance(const Position position);
ElementType retrieve(const Position position);

#endif	/* _Cursor_H */

struct Node {
	ElementType element;
	Position next;
};

struct Node cursor_space[SpaceSize];