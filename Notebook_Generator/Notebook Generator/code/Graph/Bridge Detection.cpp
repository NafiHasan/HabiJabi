vector<int> adj[N];
bool visited[N];
int low[N], tin[N], timer;
vector<pair<int, int>> bridges;
void IS_BRIDGE(int a, int b) {
	bridges.push_back({min(a, b), max(a, b)});
}
void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) low[v] = min(low[v], tin[to]);
		else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v]) IS_BRIDGE(v, to);
		}
	}
}