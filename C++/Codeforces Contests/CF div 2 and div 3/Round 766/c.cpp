#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int>ed[100005];
vector<pair<int,int>>vp(100005);
vector<bool> vis(100005, 0);
map<pair<int,int>,int>m;
vector<int>cnt(100005,0);

void dfs(int u){
	vis[u] = 1;
	for (int i : ed[u]){
		if(!vis[i]){
			// cout << i<< ' ' << u << '\n';
			if(cnt[u] >= 1){
				m[{min(i,u), max(i,u)}] = 3;
			}
			else {
				cnt[u]++;
				cnt[i]++;
				m[{min(i,u), max(i,u)}] = 2;
			}
			dfs(i);
		}
	}
}


int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin>> n;
 		for (int i=0; i<n; i++)ed[i].clear();
 		for (int i=0; i<n; i++){
 			vis[i] = 0;
 			cnt[i] = 0;
 		}
 		m.clear();
 		vp.clear();
 		bool ys = 1;
 		for (int i=0; i<n-1; i++){
 			int u, v;
 			cin >>  u >> v;
 			u--, v--;
 			ed[u].push_back(v);
 			ed[v].push_back(u);
 			vp[i] = {min(u,v), max(u,v)};
 			if(ed[u].size() > 2 || ed[v].size() > 2)ys = 0;
 		}
 		if(!ys){
 			cout << "-1\n";
 			continue;
 		}
 		dfs(0);
 		for (int i=0; i<n-1; i++){
 			cout << m[{min(vp[i].first , vp[i].second), max(vp[i].first, vp[i].second)}] << ' ';
 		}
 		cout << '\n';
 	}	
    return 0;
}