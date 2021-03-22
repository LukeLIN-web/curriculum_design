/* 打印非负整数n */
void print_out(unsigned int n){
	if (n >= 10)
		print_out(n / 10);
	print_digit(n % 10);
}
