struct LCA {
	int root;
	const int n, dep;
	vector<vector<int>> parent;
	vector<int> depth;

	LCA(const vector<vector<int>>& graph, int root, int n)
		: root(root), n(n), dep(log2(n) + 1), parent(dep, vector<int>(n)), depth(n) {
		dfs(graph, root, root, 1);
		for (int k = 0; k + 1 < dep; ++k) {
			parent.push_back(vector<int>(n, root));
			for (int v = n - 1; v >= 0; --v) {
				int par = parent[k][v];
				parent[k + 1][v] = parent[k][par];
			}
		}
	}

	void dfs(const vector<vector<int>>& graph, int from, int par, int d) {
		parent[0][from] = par;
		depth[from] = d;
		for (int to : graph[from]) {
			if (depth[to] > 0) continue;
			dfs(graph, to, from, d + 1);
		}
	}

	int query(int v1, int v2) {
		if (depth[v1] < depth[v2]) swap(v1, v2);
		for (int k = 0; k < dep; ++k) {
			if ((depth[v1] - depth[v2]) >> k & 1) {
				v1 = parent[k][v1];
			}
		}
		if (v1 == v2) { return v1; }
		for (int k = dep - 1; k >= 0; --k) {
			int p_v1 = parent[k][v1];
			int p_v2 = parent[k][v2];
			if (p_v1 == p_v2) continue;
			v1 = p_v1;
			v2 = p_v2;
		}
		assert(parent[0][v1] == parent[0][v2]);
		return parent[0][v1];
	}
};

/*verify: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
int main() {
	int n, q;
	cin >> n;
	vector<vector<int>>gr(1e5);
	for (int i = 0; i < n; ++i) {
		int k, c;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> c;
			gr[i].push_back(c);
		}
	}
	cin >> q;
	LCA lca = LCA(gr, 0, n);
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		cout << lca.query(u, v) << endl;
	}
}
*/