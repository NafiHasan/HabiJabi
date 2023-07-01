// Maximum biparite matching. Complexity : O(E*sqrt(V))
//define NIL (dummy vertex), M and INF
vector<int>g[M];
int Lmatch[M], Rmatch[M], dist[M];
bool bfs(int n) {
	queue<int>q;
	for (int u = 1; u <= n; u++) {
		if (Lmatch[u] == NIL) dist[u] = 0, q.push(u);
		else dist[u] = INF;
	}
	dist[NIL] = INF;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dist[u] < dist[NIL]) {
			for (int v : g[u]) {
				if (dist[Rmatch[v]] == INF) {
					dist[Rmatch[v]] = dist[u] + 1;
					q.push(Rmatch[v]);
				}
			}
		}
	}
	return dist[NIL] != INF;
}
bool dfs(int u) {
	if (u == NIL) return true;
	for (int v : g[u]) {
		if (dist[Rmatch[v]] == dist[u] + 1 and dfs(Rmatch[v])) {
			Rmatch[v] = u;
			Lmatch[u] = v;
			return true;
		}
	}
	dist[u] = INF;
	return false;
}
int HopcroftKarp(int n, int m) {
	fill(Lmatch, Lmatch + n + 1, 0);
	fill(Rmatch, Rmatch + m + 1, 0);
	int res = 0;
	while (bfs(n)) {
		for (int u = 1; u <= n; u++) {
			if (Lmatch[u] == NIL and dfs(u)) res++;
		}
	}
	return res;
}