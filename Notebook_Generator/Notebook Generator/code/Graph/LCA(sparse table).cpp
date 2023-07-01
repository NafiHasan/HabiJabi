vector<int>Edges[10000];
int p[10005][17], level[10005], n, lg;
bool vis[10005];
void DFS( int par, int node ) {
	vis[node] = 1;
	if ( par != -1 ) level[node] = level[par] + 1;
	p[node][0] = par;
	for ( int i = 1; i <= lg; i++ ) {
		if ( p[node][i - 1] != -1 ) p[node][i] = p[p[node][i - 1] ][i - 1];
	}
	for ( int i = 0; i < Edges[node].size(); i++ ) {
		if ( vis[ Edges[node][i] ] == 0 ) DFS( node, Edges[node][i] );
	}
	return;
}
int LCA( int u, int v ) {
	if ( level[u] < level[v] ) swap(u, v);
	for ( int i = lg; i >= 0; i-- ) {
		int par = p[u][i];
		if ( level[par] >= level[v] ) {
			u = par;
		}
	}
	if ( u == v ) return u;
	for ( int i = lg; i >= 0; i-- ) {
		int U = p[u][i];
		int V = p[v][i];
		if ( U != V ) {
			u = U; v = V;
		}
	}
	return p[u][0];
}