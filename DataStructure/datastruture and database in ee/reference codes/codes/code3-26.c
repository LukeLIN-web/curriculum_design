Status list_insert_dul(DuLinkList &L, int i, ElemType e) {
	/* 在带头结点的双链循环线性表L中第i个位置之前插入元素e */
	/* i的合法值为 1<=i<=表长 + 1 */
	if(!(p = get_elemP_dul(L, i)))	/* 在L中确定插入的位置 */
		return ERROR;
	if(!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK; 
}//ListInsert_DuL 