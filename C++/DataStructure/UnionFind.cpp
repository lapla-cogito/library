struct UnionFind {
private:
	const int n;
	int _size;
	vector<int>uf;
public:
	UnionFind(int _n) :n(_n), _size(_n), uf(_n, -1) {}
	int find(int x) { return (uf[x] < 0) ? x : uf[x] = find(uf[x]); }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -uf[find(x)]; }
	int size() { return _size; }
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) { return; }
		--_size;
		if (uf[y] < uf[x]) { swap(x, y); }
		uf[x] += uf[y];
		uf[y] = x;
	}
};

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
int main() {
	int n, q;
	cin >> n >> q;
	UnionFind uf(n);
	for (int i = 0; i < q; ++i) {
		int ident, x, y;
		cin >> ident >> x >> y;
		if (!ident) { uf.unite(x,y); }
		else { cout << uf.same(x,y) << endl; }
	}
}
*/