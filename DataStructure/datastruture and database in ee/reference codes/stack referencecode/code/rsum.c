int rsum(int list[], int n) {
	if(n <= 0)
		return 0;
	else{
		printf("%d\n", list[n - 1]);
		return rsum(list, --n);
	}
}