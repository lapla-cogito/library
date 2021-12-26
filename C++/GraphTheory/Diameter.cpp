pair<int, int> dfs(const Graph& G, int n, int par) {
	pair<int, int> res = make_pair(0, n);
	for (auto i : G[n]) {
		if (i.to == par) { continue; }
		auto next = dfs(G, i.to, n);
		next.first += i.cost;
		chmax(res, next);
	}
	return res;
}

int diatree(const Graph& G) {
	pair<int, int> p = dfs(G, 0, -1);
	pair<int, int> q = dfs(G, p.second, -1);
	return q.first;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
int main() {
	int n;
	cin >> n;
	G.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int s, t, w;
		cin >> s >> t >> w;
		addedge(s, t, w);
	}
	cout << diatree(G) << endl;
}
*/