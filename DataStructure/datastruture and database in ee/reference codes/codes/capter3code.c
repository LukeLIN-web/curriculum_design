/*	图0-6	*/
#ifndef _List_H

struct Node;
typedef struct Node *ptr_to_node;
typedef ptr_to_node List;
typedef ptr_to_node Position;

List make_empty(List L);
int is_empty(List L);
int is_last(Position P, List L);
Position find(ElementType X, List L);
void Delete(ElementType X, List L);
Position find_previous(ElementType X, List L);
void insert(ElementType X, List L, Position P);
void delete_list(List L);
Position header(List L);
Position first(List L);
Position advance(Position P);
ElementType retrieve(Position P);

#endif	/* _List_H */

struct Node{
	ElementType Element;
	Position Next;
};

/*	图0-8	*/
/* 如果L是空表，返回TRUE */
int is_empty(List L) {
	return L->Next == NULL;
}

/*	图0-9	*/
/* 如果P是表L中的最后一个位置，返回TRUE */
/* 在这种实现里参数L未被使用 */
int is_last(Position P, List L) {
	return P->Next == NULL;
}

/*	图0-10	*/
/* 返回X在表L中的位置，如果没找到X返回NULL */
		Position find(ElementType X, List L) {
			Position P;
			
/* 1*/		P = L->Next;
/* 2*/		while(P != NULL && P->Element != X)
/* 3*/			P = P->Next;
			
/* 4*/		return P;
		}
		
/*	图0-11	*/
/* 删除链表中第一个出现的X */
/* 假设使用头节点的表 */
void Delete(ElementType X, List L) {
	Position P, TmpCell;
	P = find_previous(X, L);
	if(!is_last(P, L)) {
		TempCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

/*	图0-12	*/
		/* 如果X未被找到，返回尾结点 */
		/* 假定使用带头结点的表 */
		Position find_previous(ElementType X, List L) {
			Position P;
			
/* 1*/		P = L;
/* 2*/		while(P->Next != NULL && P->Next->Element != X)
/* 3*/			P = P->Next;
				
/* 4*/		return P;
		}
		
/*	图0-13	*/
		/* 在合法结点P之后插入 */
		/* 假定使用带头结点的表 */
		/* 在这种实现里参数L未被使用 */
		void insert(ElementType X, List L, Position P) {
			Position TmpCell;
			
/* 1*/		TmpCell = malloc(sizeof(struct Node));
/* 2*/		if(TmpCel == NULL)
/* 3*/			FatalError("Out of space!");
				
/* 4*/		TmpCell->Element = X;
/* 5*/		TmpCell->Next = P->Next;
/* 6*/		P->Next = TmpCell;
		}
		
/*	图0-14	*/
		/* 不正确的删除表的算法 */
		void delete_list(List L) {
			Position P;
			
/* 1*/		P = L->Next;	/* 假定L是表头 */
/* 2*/		L->Next = NULL;
/* 3*/		while(P != NULL) {
/* 4*/			free(P);
/* 5*/			P = P->Next;
			}
		} 

/*	图0-15	*/
/* 正确的删除表的算法 */
		void delete_list(List L) {
			Position P, Tmp;
			
/* 1*/		P = L->Next;	/* 假定L是表头 */
/* 2*/		L->Next = NULL;
/* 3*/		while(P != NULL) {
/* 4*/			Tmp = P->Next;
/* 5*/			free(P);
/* 6*/			P = Tmp;
			}
		} 
		
/* 图0-18	*/
typedef struct{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} * Polynomial;

/*	图0-19	*/
void zero_polynomial(Polynomial Poly) {
	int i;
	for(i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

/*	图0-20	*/
void add_polynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
	int i;
	
	zero_polynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
	
	for(i = PolySum->HighPower; i >= 0; i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

/*	图0-21	*/
void mult_polynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd) {
	int i, j;
	
	zero_polynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	
	if(PolyProd->HighPower > MaxDegree)
		Error("Exceeded array size");
	else
		for(i = 0; i <= Poly1->HighPower; i++)
			for(j = 0; j <= Poly2->HighPower; j++)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
				
}

/*	图0-23	*/
typedef struct Node * ptr_to_node;

struct Node{
	int Coefficient;
	int Exponent;
	ptr_to_node Next;
};

typedef ptr_to_node Polynomial;	/* 根据指数将结点排序 */

/*	图0-25	*/ 
#ifndef _Cursor_H

typedef int ptr_to_node;
typedef ptr_to_node List;
typedef ptr_to_node Position;

void initialize_cursor_space(void);

List make_empty(List L);
int is_empty(const List L);
int is_last(const Position P, const List L);
Position find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position find_previous(ElementType X, const List L);
void insert(ElementType X, List L, Position P);
void delete_list(List L);
Position header(const List L);
Position first(const List L);
Position advance(const Position P);
ElementType retrieve(const Position P);

#endif	/* _Cursor_H */

struct Node{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];

/*	图cursor_alloc和CursorFree	*/ 
static Position cursor_alloc(void) {
	Position P;
	
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	
	return P;
}

static void cursor_free(Position P) {
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
} 

/*	图0-26	*/
/* 如果L是空表返回TRUE */
int is_empty(List L) {
	return CursorSpace[L].Next == 0;
} 

/*	图0-27	*/
/* 如果P是表L的最后一个结点返回TRUE */
/* 在这种实现里参数L未被使用 */
int is_last(Position P, List L) {
	return CursorSpace[P].Next == 0;
} 

/*	图0-28	*/
/* 返回X在表L中的位置，如果没找到X返回0 */ 
/* 使用头结点 */
Position find(ElementType X, List L) {
	Position P;
	
	P = CursorSpace[L].Next;
	while(P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;
	
	return P; 
}

/*	图0-29	*/
/* 删除表中出现的第一个X */
/* 假定使用了头结点 */
void Delete(ElementType X, List L) {
	Position P, TmpCell;
	
	P = find_previous(X, L);
	
	if(!is_last(P, L)) {	/* X被找到，删除该结点 */
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		cursor_free(TmpCell);
	}
} 

/*	图0-30	*/
/* 在合法的结点P之后插入 */ 
/* 假定使用带头结点的表 */
/* 在这种实现里参数L未被使用 */ 
void insert(ElementType X, List L, Position P) {
	Position TmpCell;
	
	TmpCell = cursor_alloc();
	if(TmpCell == 0)
		FatalError("Out of Space!");
	
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}

//下面开始，为清华大学《数据结构》（C语言版） 书中代码 
 
/*	图0-34	*/
Status GetElem_L(LinkList L, int i, ElemType &e) {
	//L为带头结点的单链表的头指针。
	//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	p = L->next; j = 1;	//初始化，p指向第一个结点，j为计数器 
	while(p && j < i)	//顺指针向后查找，直到p指向第i个元素或p为空 
		p = p->next;
	if(!p || j > i)
		return ERROR;	//第i个元素不存在
	e = p->data;		//取第i个元素
	return OK; 
}	//GetElem_L

/*	图0-37	*/
Status Listinsert_L(LinkList &L, int i, ElemType e) {
	//在带头结点的单链线性表L中第i个位置之前插入元素e
	p = L;
	j = 0;
	while(p && j < i - 1) {					//寻找第i-1个结点 
		p = p->next;
		j++;
	} 
	if(!p || j > i - 1)						//i小于1或者大于表长加1 
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));	//生成新结点 
	s->data = e, s->next = p->next;			//插入L中 
	p->next = s;
	return OK;
}//Listinsert_L

/*	图0-38	*/
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	//在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	p = L;
	j = 0;
	while(p->next && j < i - 1) {	//寻找第i个结点，并令p指向其前趋 
		p = p->next;
		j++;
	} 
	if(!(p->next) || j > i - 1)		//删除位置不合理 
		return ERROR;
	q = p->next, p->next = q->next;	//删除并释放结点 
	e = q->data;
	free(q);
	return OK;
}

/*	图0-44	*/
Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
	//删除带头结点的双链循环线性表L的第i个元素，i的合法值为1<=i<=表长
	if(!(p = GetElemP_DuL(L, i)))	//在L中确定第i个元素的位置指针p 
		return ERROR;				//p = NULL，即第i个元素不存在 
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK; 
}//ListDelete_DuL

/*	图0-45	*/
Status Listinsert_DuL(DuLinkList &L, int i, ElemType e) {
	//在带头结点的双链循环线性表L中第i个位置之前插入元素e
	//i的合法值为 1<=i<=表长 + 1
	if(!(p = GetElemP_DuL(L, i)))	//在L中确定插入的位置
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

