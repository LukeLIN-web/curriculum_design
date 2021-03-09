#ifndef _List_H

struct Node;
typedef struct Node *ptr_to_node;
typedef ptr_to_node List;
typedef ptr_to_node Position;

List make_empty(List list);
int is_empty(List list);
int is_last(Position position, List list);
Position find(ElementType x, List list);
void delete_element(ElementType x, List list);
Position find_previous(ElementType x, List list);
void insert(ElementType x, List list, Position position);
void delete_list(List list);
Position header(List list);
Position first(List list);
Position advance(Position position);
ElementType retrieve(Position position);

#endif	/* _List_H */

struct Node{
	ElementType element;
	Position next;
};