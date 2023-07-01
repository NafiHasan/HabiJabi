#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<long long>ed[200005], v(200005,0);
long long com = 0, z = 0;
map<long long , long long>vis;
long long xo = 0;

void dfs(int u, int tar){
	if(vis[u] > 0)return;
	vis[u]++;
	xo ^= v[u];
	// cout << xo << '\n';
	if(xo == tar) com++;
	if(xo == 0)z++;
	for (int i=0; i<ed[u].size(); i++) if(vis[ed[u][i]] == 0)dfs(ed[u][i], tar);
	return ;
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		com = 0;
 		vis.clear();
 		v.clear();
 		xo = 0;
 		int n, k;
 		cin >> n >> k;
 		for (int i=0; i<=n; i++)ed[i].clear();
 		long long ans = 0;
 		map<int,int> m;
 		int start;
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 			ans ^= v[i];
 		}
 		for (int i=0; i<n-1; i++){
 			int u, u1;
 			cin >> u >> u1;
 			u--, u1--;
 			ed[u].push_back(u1);
 			ed[u1].push_back(u);
 			m[u]++;
 			m[u1]++;
 		}
 		for (int i=0; i<n; i++){
 			if(m[i] == 1){
 				start = i;
 				break;
 			}
 		}
 		if(ans == 0)cout << "YES\n";
 		else {
 			dfs(start, ans);
 			if((com+z)>2 && (com + z)%2 && k > 2) cout << "YES\n";
 			else if(com > 1 && k>2)cout << "YES\n";
 			else cout << "NO\n";
 			// cout << start << '\n';
 		}
 		// cout<< "NO\n";
 	}	
    return 0;
}