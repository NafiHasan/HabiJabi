#define pii pair<long long,int>
vector<int>Edges[100005];
vector<long long>Cost[100005];
long long dis[100005];
int vis[100005];
void dijkstra( int source ) {
	priority_queue< pii, vector<pii>, greater<pii> >Q;
	Q.push( pii(0, source) );
	dis[source] = 0;
	pii q;
	while ( !Q.empty() ) {
		q = Q.top();
		Q.pop();
		int u = q.second;
		if ( vis[u] != -1 ) continue; // *idk why*
		vis[u] = 1; // *idk why*
		for ( int i = 0; i < Edges[u].size(); i++ ) {
			int v = Edges[u][i];
			if ( vis[v] != -1 ) continue; // *idk why*
			if ( dis[u] + Cost[u][i] < dis[ v ] ) {
				dis[ v ] = dis[u] + Cost[u][i];
				Q.push( pii( dis[v], v ) );
			}
		}
	}
	return;
}