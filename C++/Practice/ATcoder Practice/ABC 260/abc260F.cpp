#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
	FastIO;
 	int s, t, m;
 	cin >> s >> t >> m;
 	vector<int> edge[s + 5];
 	for (int i=0; i<m; i++){
 		int u, v;
 		cin >> u >> v;
 		edge[u].push_back(v);
 		// edge[v].push_back(u);
 	}
 	bool ok = 0;
 	vector<int> ans;
 	vector<vector<int>> mat(t + 5, vector<int> (t + 5, -1));
 	for (int i=1; i<=s && !ok; i++){
 		for (int j=0; j<edge[i].size() && !ok; j++){
 			for (int k=0; k<edge[i].size() && !ok; k++){
 				int u = edge[i][j], v = edge[i][k];
 				if(u == v)continue;

 				if(mat[u - s][v - s] != -1 && mat[u - s][v - s] != i){
 					// cout << i << ' ' << u << ' '<< v << '\n';
 					ok = 1;
 					ans.push_back(u);
 					ans.push_back(v);
 					ans.push_back(i);
 					ans.push_back(mat[u - s][v - s]);
 				}
 				// else if(mat[v - s][u - s] != -1){
 				// 	ok = 1;
 				// 	ans.push_back(u);
 				// 	ans.push_back(v);
 				// 	ans.push_back(i);
 				// 	ans.push_back(mat[v-s][u -s]);
 				// }
 				else {
 					mat[u - s][v - s] = i;
 					mat[v - s][u - s] = i;
 				}
 			}
 		}
 	}
 	if(ans.size() == 0)cout << "-1\n";
 	else {
 		for (int i=0; i<4; i++)cout << ans[i] << ' ';
 			cout << '\n';
 	}
    return 0;
}