vector<int>lis(vector<int>v) {
	vector<int>dp;
	for (auto i : v) {
		auto itr = lower_bound(all(dp), i);
		if (itr != dp.end()) { *itr = i; }
		else { dp.push_back(i); }
	}
	return dp;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) { cin >> v[i]; }
	cout << lis(v).size() << endl;
}
*/