#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int>edge[200005], dist(200005,0), vis(200005,0), vis2(200005,0);
vector<double>prob(200005);

void dfs(int u, int d){
	if(vis[u] > 0)return;
	vis[u]++;
	dist[u] = d;
	for (int i=0; i<edge[u].size(); i++){
		if(vis[edge[u][i]] == 0)dfs(edge[u][i] , d+1);
	}
}

void dfs2(int u, int p){
	if(vis2[u] > 0)return;
	vis2[u]++;
	if(p > 1)prob[u] = prob[p] / ((double)edge[p].size()-1);
	else if(p == 1)prob[u] = prob[p] / (double)edge[p].size();
	for (int i=0; i<edge[u].size(); i++){
		if(vis2[edge[u][i]] == 0)dfs2(edge[u][i] , u);
	}
}

int main()
{
	fast_io();
 	int n;
 	cin>> n;
 	for (int i=0; i<n-1; i++){
 		int u, v;
 		cin >> u >> v;
 		edge[u].push_back(v);
 		edge[v].push_back(u);
 	}
 	dfs(1,0);
 	double cnt = 0;
 	// for (int i=2; i<=n; i++){
 	// 	if((int)edge[i].size() == 1)cnt++;
 	// }
 	double ans = 0;
 	prob[1] = 1.0;
 	dfs2(1, 0);
 	// for(int i=1; i<=n; i++)cout << prob[i] << ' ' ;
 	// 	cout << '\n';
 	for (int i=2; i<=n; i++){
 		if((int)edge[i].size() == 1)ans+= prob[i] * dist[i];
 	}
 	// ans/= cnt;
 	if(n==1)cout << 0 <<'\n';
 	else cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}