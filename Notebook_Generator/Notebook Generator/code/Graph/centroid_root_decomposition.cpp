const int MAXN = 100050;
const int LOGN = 17;
int par[LOGN][MAXN];			// par[i][v]: (2^i)th ancestor of v
int level[MAXN], sub[MAXN];		// sub[v]: size of subtree whose root is v
int ctPar[MAXN], n;	// ctPar[v]: parent of v in centroid tree
vector<int> adj[MAXN];
bool vis[MAXN];
int ans[MAXN];		// ans[v]: shortest distance between v and red nodes in subtree corresponding to centroid v
long long INF = 1e18;
// calculate level by dfs
void dfsLevel(int node, int pnode) {
	for(auto cnode : adj[node]) {
		if(cnode != pnode) {
			par[0][cnode] = node;
			level[cnode] = level[node] + 1;
			dfsLevel(cnode, node);
		}
	}
}
void preprocess() {
	level[0] = 0; par[0][0] = 0;
	dfsLevel(0, -1);
	for(int i = 1; i < LOGN; i++) 
		for(int node = 0; node < n; node++) 
			par[i][node] = par[i-1][par[i-1][node]];
}
int lca(int u, int v) {
	if(level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	// make u, v same level
	for(int i = 0; i < LOGN; i++) {
		if(d & (1 << i)) {
			v = par[i][v];
		}
	}
	if(u == v) return u;
	// find LCA
	for(int i = LOGN - 1; i >= 0; i--) {
		if(par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}
int dist(int u, int v) {
	return level[u] + level[v] - 2 * level[lca(u, v)];
}
/* Centroid decomposition */
// Calculate size of subtrees by dfs
void dfsSubtree(int node, int pnode) {
	sub[node] = 1;
	for(auto cnode : adj[node]) {
		if(cnode != pnode && vis[cnode] == 0) {
			dfsSubtree(cnode, node);
			sub[node] += sub[cnode];
		}
	}
}
// find Centroid
int dfsCentroid(int node, int pnode, int size) {
	for(auto cnode : adj[node]) {
		if(cnode != pnode && sub[cnode] > size / 2 && vis[cnode] == 0 )
			return dfsCentroid(cnode, node, size);
	}
	return node;
}
// Centroid decomposition
void decompose(int node, int pCtr) {
	dfsSubtree(node, -1);
	int ctr = dfsCentroid(node, node, sub[node]);
	vis[ctr] = 1;
	if(pCtr == -1)
		pCtr = ctr;	// root of centroid tree
	ctPar[ctr] = pCtr;

	for(auto cnode : adj[ctr]) {
		if( vis[cnode] == 0 ) decompose(cnode, ctr);
	}
	adj[ctr].clear();
}
// color node v red
void update(int v) {
	int rNode = v;
	while(1) {
		ans[v] = min(ans[v], dist(rNode, v));
		if(v == ctPar[v]) break;
		v = ctPar[v];
	}
}
// reply query
int query(int v) {
	int start = v;
	int minD = INF;
	while(1) {
		minD = min(minD, dist(start, v) + ans[v]);
		if(v == ctPar[v]) break;
		v = ctPar[v];
	}
	return minD;
}
int main() {
	preprocess();
	decompose(0, -1);
	fill(ans, ans + n, INF);
	update(0);
}
