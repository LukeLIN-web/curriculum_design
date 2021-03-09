/* 在结点listentry之后插入一个新的结点，返回新结点的指针 */
SListEntry *slist_insert(SListEntry **list, SListEntry *listentry, SListValue data){
	SListEntry *newentry;
	newentry = (SListEntry *)malloc(sizeof(SListEntry));
	if(newentry == NULL)
	    return NULL;
	newentry->data = data;
	newentry->next = listentry->next;
	listentry->next = newentry;
	return newentry;
}