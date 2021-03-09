void polynomial_zero(ArrayList *poly) {
	int i;
	for(i = 0; i < poly->_alloced; i++)
		*((double *)(poly->data[i])) = 0;   /* 使用之前需要分配内存 */
	/* 最高次数为poly->length-1，这里length的含义是ArrayList已经使用的空间数 */
	poly->length = 1;
}