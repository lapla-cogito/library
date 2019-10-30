int binary(int n) {
	int res = 0;
	for (int i = 0; n > 0; i++) {
		res += (n % 2) * pow(10, i);
		n /= 2;
	}
	return res;
}
