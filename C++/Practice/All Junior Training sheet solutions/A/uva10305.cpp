#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200;

vector<int>ans, edge[N];
vector<bool> vis(N, 0);

void dfs(int u){
	vis[u] = 1;
	for (int i : edge[u]){
		if(!vis[i])dfs(i);
	}
	ans.push_back(u);
}

int main()
{
	fast_io();
 	while(1){
 		ans.clear();
 		for (int i=0; i<200; i++)vis[i] = 0;
 		for (int i=0; i<200; i++)edge[i].clear();
 		int n, m;
 		cin >> n >> m;
 		if(n == 0 && m == 0)return 0;
 		for (int i=0; i<m; i++){
 			int u, v;
 			cin >> u >> v;
 			edge[u].push_back(v);
 		}
 		for (int i=1; i<=n; i++){
 			if(!vis[i])dfs(i);
 		}
 		reverse(ans.begin(), ans.end());
 		for (int i=0; i<n; i++){
 			if(i)cout << " ";
 			cout << ans[i];
 		}
 		cout << '\n';
 	}
    return 0;
}