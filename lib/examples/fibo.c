

int fibo(int num) {

	int a = 0, b = 1;
	int fib = 0;

	for(int i = 0; i < num - 1; i++) {
		fib = a + b; // 1
		a = b; // 1
		b = fib; // 1 
	}

	return fib;
}
