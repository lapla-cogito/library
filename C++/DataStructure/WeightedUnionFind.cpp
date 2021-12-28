class wUnionFind {
private:
	vector<int>par, rank, weight;

public:
	void init(int size) {
		par.resize(size + 1);
		for (int i = 0; i < size + 1; ++i) { par[i] = i; }
		rank.resize(size + 1, 0);
		weight.resize(size + 1, 0);
	}

	int find(int x) {
		if (par[x] == x) { return x; }
		int res = find(par[x]);
		weight[x] += weight[par[x]];
		par[x] = res;
		return res;
	}

	void unite(int x, int y, int w) {
		int xx = x, yy = y;
		x = find(x), y = find(y);
		w += weight[yy] - weight[xx];
		if (x == y) { return; }
		if (rank[x] < rank[y]) {
			par[x] = y;
			weight[x] = w;
		}
		else {
			par[y] = x;
			weight[y] = -w;
			if (rank[x] == rank[y]) { ++rank[x]; }
		}
	}

	int issame(int x, int y) { return find(x) == find(y); }

	int diff(int x, int y) { return weight[y] - weight[x]; }
};

int main() {
	int n, q;
	cin >> n >> q;
	wUnionFind uf;
	uf.init(n);
	for (int i = 0; i < q; ++i) {
		int ident, x, y, z;
		cin >> ident;
		if (!ident) {
			cin >> x >> y >> z;
			uf.unite(x, y, z);
		}
		else {
			cin >> x >> y;
			if (uf.find(x) != uf.find(y)) { cout << "?" << endl; }
			else { cout << uf.diff(y, x) << endl; }
		}
	}
}