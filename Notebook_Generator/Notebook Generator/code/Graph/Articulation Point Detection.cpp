vector<int> adj[N];
bool vis[N], articulation[N];
int low[N], tin[N], taim;
void dfs(int node, int par = -1) {
	vis[node] = 1;
	tin[node] = low[node] = taim++;
	int children = 0;
	for (int x : adj[node]) {
		if (x == par) continue;
		if (vis[x]) low[node] = min(low[node], tin[x]);
		else {
			dfs(x, node);
			low[node] = min(low[node], low[x]);
			if (low[x] >= tin[node] && par != -1) {
				articulation[node] = 1;
			}
			children++;
		}
	}
	if (children > 1 and par == -1) articulation[node] = 1;
}