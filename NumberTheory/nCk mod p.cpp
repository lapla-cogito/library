void COMinit() {
	fac[0] = 1, fac[1] = 1, finv[0] = 1, finv[1] = 1, inv[1] = 1;
	for (int i = 2; i < SIZE; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

//calc
long long COM(long long n, long long k) {
	if (n < k) { return 0; }
	if (n < 0 || k < 0) { return 0; }
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//ex
int main() {
	//Don't forget!!
	COMinit();
	long long a, b;
	cin >> a >> b;
	cout << COM(a,b) << endl;
}
