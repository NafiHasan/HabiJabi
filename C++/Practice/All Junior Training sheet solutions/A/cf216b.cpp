#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200;
vector<int>edge[N], c(N,0);
vector<bool> vis(N, 0);

void dfs(int u, int clr){
	// if(c[u] != clr){
	// 	c[u] = -1;
	// 	return ;
	// }
	vis[u] = 1;
	if(clr == 1)clr++;
	else clr--;
	for (int i=0; i<edge[u].size(); i++){
		if(vis[edge[u][i]] == 0){
			c[edge[u][i]] = clr;
			dfs(edge[u][i], clr);
		}
	}
}

int main()
{
	fast_io();
 	int n, m;
 	cin >> n >> m;
 	for (int i=0; i<m; i++){
 		int u, v;
 		cin >> u >> v;
 		u-- , v--;
 		edge[u].push_back(v);
 		edge[v].push_back(u);
 	}
 	for (int i=0; i<n; i++){
 		if(vis[i] == 0){
 			vis[i] = 1;
 			c[i] = 1;
 			dfs(i, 1);
 		}
 	}
 	int cnt = 0;
 	for (int i=0; i<n; i++){
 		if(c[i] == -1)continue;
 		for (int j=0; j<edge[i].size(); j++){
 			if(c[i] == c[edge[i][j]]){
 				c[edge[i][j]] = -1;
 				cnt++;
 			}
 		}
 	}
 	if((n-cnt) % 2)cnt++;
 	cout << cnt << '\n';
    return 0;
}