Status list_insert(LinkList &L, int i, ElemType e) {
	//在带头结点的单链线性表L中第i个位置之前插入元素e
	p = L;
	j = 0;
	while(p && j < i - 1) { //寻找第i-1个结点
		p = p->next;
		j++;
	} 
	if(!p || j > i - 1) //i小于1或者大于表长加1
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));    //生成新结点
	s->data = e, s->next = p->next; //插入L中
	p->next = s;
	return OK;
}//Listinsert_L