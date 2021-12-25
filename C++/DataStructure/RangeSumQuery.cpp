class RSQ {
private:
	ll n;
	vector<ll>node;

public:
	void init(ll size) {
		n = 1;
		while (n < size) n *= 2;
		node.resize(2 * n - 1, 0);
	}

	void update(ll i, ll x) {
		i += n - 1;
		node[i] += x;
		while (i > 0) {
			i = (i - 1) / 2;
			node[i] = node[2 * i + 1] + node[2 * i + 2];
		}
	}

	ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) { r = n; }
		if (r <= a || b <= l) { return 0; }
		if (a <= l && r <= b) { return node[k]; }
		ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
};

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
int main() {
	int n, q;
	cin >> n >> q;
	RSQ rsq;
	rsq.init(n);
	for (int i = 0; i < q; ++i) {
		int ident, x, y;
		cin >> ident >> x >> y;
		--x;
		if (!ident) { rsq.update(x, y); }
		else { cout << rsq.query(x, y) << endl; }
	}
}
*/