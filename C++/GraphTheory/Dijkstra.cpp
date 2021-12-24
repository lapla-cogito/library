void dijkstra(int n) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>que;
	fill(dij.begin(), dij.end(), INF);
	dij[n] = 0;
	que.push(pair<long long, long long>(0, n));

	while (!que.empty()) {
		pair<long long, long long>p = que.top();
		que.pop();
		long long mon = p.second;
		if (dij[mon] < p.first) continue;
		for (int i = 0; i < G[mon].size(); ++i) {
			edge e = G[mon][i];
			if (dij[e.to] > dij[mon] + e.cost) {
				dij[e.to] = dij[mon] + e.cost;
				que.push(pair<long long, long long>(dij[e.to], e.to));
			}
		}
	}
}

/*verify: https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f
int main() {
	int n, k;
	cin >> n >> k;
	dij.resize(n);
	G.resize(n);
	for (int i = 0; i < k; ++i) {
		int d;
		cin >> d;
		if (d) {
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			addedge(a, b, c);
		}
		else {
			int a, b;
			cin >> a >> b;
			--a, --b;
			dijkstra(a);
			cout << (dij[b] == INF ? -1 : dij[b]) << endl;
		}
	}
}
*/