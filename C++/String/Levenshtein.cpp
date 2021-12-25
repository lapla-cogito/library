int levenshtein(string s, string t) {
	int slen = s.length(), tlen = t.length();
	vector<vector<ll>>v(slen + 1, vector<ll>(tlen + 1, INF));

	for (int i = 0; i <= slen; ++i) { v[i][0] = i; }
	for (int i = 0; i <= tlen; ++i) { v[0][i] = i; }
	for (int i = 0; i < slen; ++i) {
		for (int j = 0; j < tlen; ++j) {
			int cost;
			s[i] == t[j] ? cost = 0 : cost = 1;
			v[i + 1][j + 1] = min({ v[i][j + 1] + 1,v[i + 1][j] + 1,v[i][j] + cost });
		}
	}
	return v[slen][tlen];
}

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E
int main() {
	string s, t;
	cin >> s >> t;
	cout << levenshtein(s, t) << endl;
}
*/