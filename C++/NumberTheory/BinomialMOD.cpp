void COMinit() {
	fac[0] = 1, fac[1] = 1, finv[0] = 1, finv[1] = 1, inv[1] = 1;
	for (int i = 2; i < SIZE; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll COM(ll n, ll k) {
	if (n < k) { return 0; }
	if (n < 0 || k < 0) { return 0; }
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/*verify: https://atcoder.jp/contests/agc025/tasks/agc025_b
ll n, a, b, k, ans;
int main() {
	COMinit();
	cin >> n >> a >> b >> k;
	for (int i = 0; a * i <= k; ++i) {
		if (!((k - a * i) % b)) { ans += COM(n, i) * COM(n, (k - a * i) / b); ans %= MOD; }
	}
	cout << ans % MOD << endl;
}
*/