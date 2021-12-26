class BIT {
private:
	int n;
	vector<int>node;
public:
	void init(int size) {
		n = size;
		node.resize(n + 1, 0);
	}

	void update(int i, int x) {
		while (i <= n) {
			node[i] += x;
			i += i & -i;
		}
	}

	int query(int i) {
		int res = 0;
		while (i > 0) {
			res += node[i];
			i -= i & -i;
		}
		return res;
	}
};

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
int main() {
	int n, q;
	cin >> n >> q;
	BIT fen;
	fen.init(n);
	for (int i = 0; i < q; ++i) {
		int ident, x, y;
		cin >> ident >> x >> y;
		--x;
		if (!ident) { fen.update(x + 1, y); }
		else { cout << fen.query(y) - fen.query(x) << endl; }
	}
}
*/