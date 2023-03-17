#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int n;
 	cin >> n;
 	vector<pair<int,int>> vp[n];
 	map<int, int> mp;
 	map<pair<int,int>, int> cnt;
 	for (int i=0; i<n; i++){
 		int m;
 		cin >> m;
 		while(m--){
 			int u, v;
 			cin >> u >> v;
 			vp[i].push_back({u,v});
 			mp[u] = max(mp[u], v);
 			cnt[{u,v}]++;
 		}
 	}	
 	int ans = 0;
 	bool have = 0;
 	for (int i=0; i<n; i++){
 		bool ok = 0;
 		for (int j=0; j<vp[i].size(); j++){
 			if(mp[vp[i][j].first] == -1)continue;
 			if(vp[i][j].second == mp[vp[i][j].first] && cnt[vp[i][j]] == 1){
 				ans++;
 				ok = 1;
 				break;
 			}
 		}
 		if(ok){
 			for (int j=0; j<vp[i].size(); j++){
 				if(vp[i][j].second == mp[vp[i][j].first]){
 					mp[vp[i][j].first] = -1;
 				}
 			}
 		}
 		else have = 1;
 	}
 	if(have)ans++;
 	cout << ans << '\n';
    return 0;
}