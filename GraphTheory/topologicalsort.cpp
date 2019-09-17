vector<vector<long long>>v;

vector<long long>tsort(long long n) {
	vector<long long>mon(n + 1), ans;
	stack<long long>s;
	for (long long i = 1; i <= n; ++i) {
		for (auto j : v[i]) { ++mon[j]; }
	}
	for (long long i = 1; i <= n; ++i) {
		if (mon[i] == 0) { s.push(i); }
	}
	while (s.size()) {
		long long mmon = s.top();
		s.pop();
		ans.push_back(mmon);
		for (auto i : v[mmon]) {
			--mon[i];
			if (mon[i] == 0) { s.push(i); }
		}
	}
	return ans;
}

//ex(NIKKEI D)
int main() {
	long long a, b;
	cin >> a >> b;
	vector<long long>aa(a + b - 1), bb(a + b - 1);
	map<long long, long long>fi;
	v.resize(a + 1);
	for (int i = 0; i < a + b - 1; ++i) { cin >> aa[i] >> bb[i]; }
	for (int i = 0; i < a + b - 1; ++i) { v[aa[i]].push_back(bb[i]); }
	auto mon = tsort(a);
	for (int i = 0; i < a; ++i) { fi[mon[i]] = i; }
	vector<long long>anss(a + 1, mon[0]);
	anss[mon[0]] = 0;
	for (int i = 0; i < a + b - 1; ++i) {
		if (fi[anss[bb[i]]] < fi[aa[i]]) { anss[bb[i]] = aa[i]; }
	}
	for (long long i = 1; i <= a; ++i) { cout << anss[i] << endl; }
}