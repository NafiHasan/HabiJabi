#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		vector<int> edges[n];
 		vector<pair<int,int>>ed(n);
 		for (int i=0; i<n-1; i++){
 			int u, v;
 			cin >> u >> v;
 			u--, v--;
 			ed[u].first++;
 			edges[u].push_back(v);
 			edges[v].push_back(u);
 			ed[v].first++;
 			ed[u].second = u;
 			ed[v].second = v;
 		}
 		sort(ed.begin(), ed.end());
 		int ans = n, cnt = 0;
 		for (int i=1; i<=k; i++){
 			// if(ed[i].first == 0)continue;
 			for (int j =0 ; j<n; j++){
 				if(j && ed[j].first != ed[j-1].first)break;
 				for (int u = 0; u < edges[ed[j].second].size(); u++){
 					ed[edges[]]
 				}
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}