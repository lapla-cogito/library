string LCS(string a, string b) {
	string res;
	vector<vector<int>>dp(a.length() + 1, vector<int>(b.length() + 1, 0));
	for (int i = 0; i < a.length(); ++i) {
		for (int j = 0; j < b.length(); ++j) {
			if (a[i] == b[j]) { dp[i + 1][j + 1] = dp[i][j] + 1; }
			else { dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]); }
		}
	}

	int n = a.length(), m = b.length();
	while (n && m) {
		if (dp[n - 1][m] == dp[n][m]) { --n; }
		else if (dp[n][m - 1] == dp[n][m]) { --m; }
		else {
			res += a[n - 1];
			--n, --m;
		}
	}reverse(all(res));

	return res;
}

/*verify: https://atcoder.jp/contests/dp/tasks/dp_f
int main() {
	string s, t;
	cin >> s >> t;
	cout << LCS(s, t) << endl;
}
*/