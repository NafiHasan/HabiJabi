#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 100005;

vector<int>ans, edge[N];
vector<bool> vis(N, 0);

void dfs(int u){
	vis[u] = 1;
	for (int i : edge[u]){
		if(!vis[i]) dfs(i);
	}
	ans.push_back(u);
}


int main()
{
	fast_io();
 	int n, k;
 	cin >> n >> k;
 	for (int i=0; i<k; i++){
 		int cnt;
 		cin >> cnt;
 		while(cnt--){
 			int u;
 			cin >> u;
 			edge[i+1].push_back(u);
 		}
 	}
 	for (int i=1; i<=n; i++){
 		if(!vis[i])dfs(i);
 	}
 	reverse(ans.begin(), ans.end());
 	// for (int i=0; i<n; i++)cout << ans[i] << ' ';
 	// cout << '\n'; 
 	vector<int>p(n+1,0);
 	for (int i=1; i<ans.size(); i++)p[ans[i]] = ans[i-1];
 	for (int i=1; i<=n; i++)cout << p[i] << '\n';
    return 0;
}