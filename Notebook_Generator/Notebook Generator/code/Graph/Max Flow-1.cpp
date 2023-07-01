int graph[105][105];
int rgraph[105][105];
int par[105];
int n;
int bfs( int s, int d ) {
	bool vis[105];
	memset( vis, 0, sizeof(vis) );
	queue<int>Q;
	Q.push(s);
	while ( !Q.empty() ) {
		int q = Q.front();
		Q.pop();
		for ( int i = 1; i <= n; i++ ) {
			if ( vis[i] == 0 && rgraph[q][i] > 0 ) {
				vis[i] = 1;
				par[i] = q;
				if ( i == d ) return 1;
				Q.push(i);
			}
		}
	}
	return 0;
}
int max_flow( int s, int d ) {
	int total_flow = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) rgraph[i][j] = graph[i][j];
	}
	int mn;
	while ( bfs( s, d ) == 1 ) {
		mn = INT_MAX;
		for ( int child = d; child != s; child = par[child] ) {
			int P = par[child];
			mn = min(mn, rgraph[P][child] );
		}
		for ( int child = d; child != s; child = par[child] ) {
			int P = par[child];
			rgraph[P][child] -= mn;
			rgraph[child][P] += mn;
		}
		total_flow += mn;
	}
	return total_flow;
}