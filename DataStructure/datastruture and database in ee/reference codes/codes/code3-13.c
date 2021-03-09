void polynomial_mult(ArrayList *poly1, ArrayList *poly2, ArrayList **polyMult) {
	int i, j, l;
	l = (poly1->length-1) + (poly2->length-1) + 1;	//poly1和poly2的最高次数之和为相乘后的最高次数
	(*polyMult) = arraylist_new(l);
	for(i = 0; i < (*polyMult)->_alloced; i++)
		(*polyMult)->data[i] = (double *)malloc(sizeof(double));
	polynomial_zero(*polyMult);
	(*polyMult)->length = l;

	for(i = 0; i < poly1->length; i++)
		for(j = 0; j < poly2->length; j++)
			*(double *)((*polyMult)->data[i+j]) += *(double *)(poly1->data[i]) * *(double *)(poly2->data[j]);
}