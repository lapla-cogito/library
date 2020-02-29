struct ConvexHullTrick {
	//(slope,intercept)
	deque<pair<ll, ll> > dq;

	void add(ll a, ll b) {
		pair<ll, ll> p0 = make_pair(a, b);
		while (dq.size() >= 2) {
			ll sz = dq.size();
			std::pair<ll, ll> p1 = dq[sz - 1];
			std::pair<ll, ll> p2 = dq[sz - 2];
			if ((p0.second - p1.second) * (p0.first - p2.first) < (p0.second - p2.second) * (p0.first - p1.first)) { break; }
			dq.pop_back();
		}
		dq.push_back(p0);
	}

	ll query(ll x) {
		while (dq.size() >= 2) {
			ll v1 = dq[0].first * x + dq[0].second;
			ll v2 = dq[1].first * x + dq[1].second;
			if (v1 <= v2) { break; }
			dq.pop_front();
		}
		return dq[0].first * x + dq[0].second;
	}
};


/*ex)https://atcoder.jp/contests/dp/submissions/10406961 (EDPC-Z Frog 3)
ll a, b;
vector<ll>v, dp;
int main() {
	cin >> a >> b;
	v.resize(a), dp.resize(a);

	for (int i = 0; i < a; ++i) { cin >> v[i]; }

	ConvexHullTrick cht;
	dp[0] = 0;
	cht.add(-2 * v[0], v[0] * v[0]);

	for (int i = 1; i < a; ++i) {
		dp[i] = cht.query(v[i]) + v[i] * v[i] + b;
		cht.add(-2 * v[i], v[i] * v[i] + dp[i]);
	}

	cout << dp[a - 1] << endl;
}
*/
