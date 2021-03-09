void polynomial_add(ArrayList *poly1, ArrayList *poly2, ArrayList **polySum) {
	int i, l;
	//取poly1和poly2最高次数的较大者为相加后的最高次数
	l = poly1->length;
	if(poly2->length > poly1->length)
		l = poly2->length;
	*polySum = arraylist_new(l);
	//分配内存空间
	for(i = 0; i < (*polySum)->_alloced; i++)
		(*polySum)->data[i] = (double *)malloc(sizeof(double));
	polynomial_zero(*polySum);	//初始化
	(*polySum)->length = l;

	for(i = 0; i < (*polySum)->length; i++)
		*(double *)((*polySum)->data[i]) = *(double *)(poly1->data[i]) + *(double *)(poly2->data[i]);
}