class RSQ {
private:
	int n;
	vector<int>node;

public:
	void init(int size) {
		n = 1;
		while (n < size) { n *= 2; }
		node.resize(2 * n - 1, 0);
	}

	void update(int i, int x) {
		i += n - 1;
		node[i] += x;
		while (i > 0) {
			i = (i - 1) / 2;
			node[i] = node[2 * i + 1] + node[2 * i + 2];
		}
	}

	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) { r = n; }
		if (r <= a || b <= l) { return 0; }
		if (a <= l && r <= b) { return node[k]; }
		int vl = query(a, b, 2 * k + 1, l, (l + r) / 2), vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
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