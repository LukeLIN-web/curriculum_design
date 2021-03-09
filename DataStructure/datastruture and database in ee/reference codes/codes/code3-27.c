void polynomial_zero(PolyList *poly) {
	PolyList next, p = *poly;
	while (p != NULL) {
		next = p->next;
		free(p->data); 
		free(p);
		p = next;
	}
	*poly = NULL;
}