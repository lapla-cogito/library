vector<long long>dij;//distance
struct edge { int to, cost; };
vector<vector<edge>>G;

void dijkstra(int n) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>que;
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
