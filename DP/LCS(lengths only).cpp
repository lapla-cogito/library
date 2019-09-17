ll LCS(string a, string b) {
	ll dp[5005][5005];
	for (int i = 0; i < a.length(); ++i) {
		for (int j = 0; j < b.length(); ++j) {
			if (a[i] == b[j]) { dp[i + 1][j + 1] = dp[i][j] + 1; }
			else { dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]); }
		}
	}
	return dp[a.length()][b.length()];
}