vector<int>z_algo(string s) {
	int l = s.length();
	vector<int>prefi(l, l);
	int i = 1, j = 0;
	while (i < l) {
		while (i + j < l && s[j] == s[i + j]) { ++j; }
		prefi[i] = j;
		if (!j) {
			++i;
			continue;
		}
		int temp = 1;
		while (i + temp < l && prefi[temp] + temp < j) {
			prefi[i + temp] = prefi[temp];
			++temp;
		}
		i += temp, j -= temp;
	}
	return prefi;
}

/*verify: https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_h
int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<ll>v = {}, uku(n + 1, 0);
	v.push_back(1);
	for (int i = 0; i < n; ++i) { v.push_back((26 * v[v.size() - 1]) % MOD); }
	auto res = z_algo(s);
	for (int i = 1; i < n; ++i) { ++uku[i], --uku[i + res[i]]; }
	for (int i = 0; i < n; ++i) { uku[i + 1] += uku[i]; }

	ll ans = v[n];

	for (int i = n - 1; i >= 0; --i) {
		if (!uku[n - 1 - i]) { ans = (ans + MOD - v[i]) % MOD; }
	}

	cout << ans << endl;
}
*/