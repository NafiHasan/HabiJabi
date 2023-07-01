/*In a directed graph, an SCC is a connected
component where all nodes are pairwise
reachable. ,→
,→
condesation graph is the DAG built on a directed
,→ graph by compressing each SCC into a node.
define M */
vector<int>g[M], gr[M];
set<int>gc[M];
int vis[M], id[M], sz[M];
vector<int>order, comp, roots;
namespace SCC {
void addEdge(int u, int v) {
	g[u].push_back(v), gr[v].push_back(u);
}
void dfs1(int u) {
	vis[u] = 1;
	for (int x : g[u])
		if (!vis[x]) dfs1(x);
	order.push_back(u);
}
void dfs2(int u) {
	vis[u] = 1;
	comp.push_back(u);
	for (int x : gr[u])
		if (!vis[x]) dfs2(x);
}
void condense(int n) {
	fill(vis, vis + n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs1(i);
	reverse(order.begin(), order.end());
	fill(vis, vis + n + 1, 0);
	for (int u : order) {
		if (!vis[u]) {
			dfs2(u); //this part of the code processes components, returns them in comp
			for (int v : comp) id[v] = u;
			sz[u] = (int)comp.size();
			roots.push_back(u);
			comp.clear();
		}
	}
	fill(vis, vis + n + 1, 0);
	for (int u = 1; u <= n; u++) {
		for (int v : g[u]) {
			if (id[u] != id[v])
				gc[id[u]].insert(id[v]);
		}
	}
}
void reset(int n) {
	order.clear(), comp.clear(), roots.clear();
	for (int i = 1; i <= n; i++) {
		g[i].clear(), gr[i].clear(), gc[i].clear();
		id[i] = vis[i] = sz[i] = 0;
	}
}
}