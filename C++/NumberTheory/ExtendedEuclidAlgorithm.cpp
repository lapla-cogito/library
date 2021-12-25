ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll g = a;
	x = 1, y = 0;
	if (b) {
		g = extgcd(b, a % b, y, x);
		y -= a / b * x;
	}
	return g;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
int main() {
	ll n, m, x, y;
	cin >> n >> m;
	extgcd(n, m, x, y);
	cout << x << " " << y << endl;
}
*/