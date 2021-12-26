int euler_phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; ++i) {
		if (!(n % i)) {
			res -= res / i;
			while (!(n % i)) { n /= i; }
		}
	}
	if (n > 1) { res -= res / n; }
	return res;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
int main() {
	ll n;
	cin >> n;
	cout << euler_phi(n) << endl;
}
*/