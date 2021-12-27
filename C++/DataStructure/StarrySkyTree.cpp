class Starryskytree {
private:
	int n;
	vector<int>node, nodeadd;

public:
	void init(int size) {
		n = 1;
		while (n < size) { n *= 2; }
		node.resize(2 * n - 1, 0);
		nodeadd.resize(2 * n - 1, 0);
	}

	void update(int s, int t, int x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) { r = n; }
		if (r <= s || t <= l) { return; }
		if (s <= l && r <= t) {
			nodeadd[k] += x;
			return;
		}
		update(s, t, x, 2 * k + 1, l, (l + r) / 2);
		update(s, t, x, 2 * k + 2, (l + r) / 2, r);
		node[k] = min(node[2 * k + 1] + nodeadd[2 * k + 1], node[2 * k + 2] + nodeadd[2 * k + 2]);
	}

	int query(int s, int t, int k = 0, int l = 0, int r = -1) {
		if (r < 0) { r = n; }
		if (r <= s || t <= l) { return INF; }
		if (s <= l && r <= t) { return node[k] + nodeadd[k]; }
		int left = query(s, t, 2 * k + 1, l, (l + r) / 2), right = query(s, t, 2 * k + 2, (l + r) / 2, r);
		return min(left, right) + nodeadd[k];
	}
};

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H
int main() {
	int n, q;
	cin >> n >> q;

	Starryskytree sst;
	sst.init(n);

	for (int i = 0; i < q; ++i) {
		int ident, s, t, x;
		cin >> ident;
		if (!ident) {
			cin >> s >> t >> x;
			sst.update(s, t + 1, x);
		}
		else {
			cin >> s >> t;
			cout << sst.query(s, t + 1) << endl;
		}
	}
}
*/