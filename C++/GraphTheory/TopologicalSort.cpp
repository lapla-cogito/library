vector<int>tsort(vector<vector<int>> v) {
	int n = v.size();
	vector<int>mon(n, 0), res;
	stack<int>s;
	for (int i = 0; i < n; ++i) {
		for (auto j : v[i]) { ++mon[j]; }
	}
	for (int i = 0; i < n; ++i) {
		if (mon[i] == 0) { s.push(i); }
	}
	while (s.size()) {
		int mmon = s.top();
		s.pop();
		res.push_back(mmon);
		for (auto i : v[mmon]) {
			--mon[i];
			if (mon[i] == 0) { s.push(i); }
		}
	}
	return res;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
int main() {
	ll v, e;
	cin >> v >> e;
	vector<vector<int>>gr(v);
	for (int i = 0; i < e; ++i) {
		int s, t;
		cin >> s >> t;
		gr[s].push_back(t);
	}
	auto res = tsort(gr);
	for (auto i : res) { cout << i << endl; }
}
*/