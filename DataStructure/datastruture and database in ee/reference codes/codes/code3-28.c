void polynomial_add(PolyList poly1, PolyList poly2, PolyList *polySum) {
	PolyList p, q, head = NULL;
	PolyNode *newnode;
	p = poly1;
	q = poly2;
	while(p != NULL && q != NULL){	//两个多项式链表均还有数据 
		newnode = (PolyNode *)malloc(sizeof(PolyNode));
		//指数相等则系数相加，存入新多项式中
		if(((PolyNode *)p->data)->exponent == ((PolyNode *)q->data)->exponent) {	 	
			newnode->coefficient = ((PolyNode *)p->data)->coefficient + ((PolyNode *)q->data)->coefficient;
			newnode->exponent = ((PolyNode *)p->data)->exponent;
			p = p->next;
			q = q->next;
		}
		//指数不相等则先存入指数较大的项 
		else if(((PolyNode *)p->data)->exponent > ((PolyNode *)q->data)->exponent) {
			newnode->coefficient = ((PolyNode *)p->data)->coefficient;
			newnode->exponent = ((PolyNode *)p->data)->exponent;
			p = p->next; 
		}
		else {
			newnode->coefficient = ((PolyNode *)q->data)->coefficient;
			newnode->exponent = ((PolyNode *)q->data)->exponent;
			q = q->next; 
		}
		if(newnode->coefficient == 0) {	//系数为0的项不存储 
			free(newnode);
			continue;	
		}
		slist_prepend(&head, newnode);
	}
	//仅多项式A还有剩余数据 
	while(p != NULL) {	
		newnode = (PolyNode *)malloc(sizeof(PolyNode));
		newnode->coefficient = ((PolyNode *)p->data)->coefficient;
		newnode->exponent = ((PolyNode *)p->data)->exponent;
		p = p->next;
		slist_prepend(&head, newnode);
	}
	//仅多项式B还有剩余数据
	while(q != NULL) {	
		newnode = (PolyNode *)malloc(sizeof(PolyNode));
		newnode->coefficient = ((PolyNode *)q->data)->coefficient;
		newnode->exponent = ((PolyNode *)q->data)->exponent;
		q = q->next; 
		slist_prepend(&head, newnode);
	}
	*polySum = head;
}