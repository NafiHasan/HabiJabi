#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		vector<vector<int>> v(n);
 		for (int i=0; i<n; i++){
 			int x; cin >> x;
 			v[i].push_back(x);
 			for (int j = 2; j <= min(k, x); j++){
 				v[i].push_back(x/j);
 			}
 			sort(v[i].begin(), v[i].end());
 		}
 		// for (int i=0; i<n; i++){
 		// 	for (int j=0; j<v[i].size(); j++){
 		// 		cout << v[i][j] << ' ';
 		// 	}
 		// 	cout << '\n';
 		// }
 		int ans = 3010;
 		for (int i=0; i<=3010; i++){
 			int mx = 0;
 			for (int j=0; j<n; j++){
 				int lo = 0, hi = v[j].size() - 1, mid, last = 100010;
 				while(lo <= hi){
 					mid = (lo + hi)/2;
 					if(v[j][mid] >= i){
 						last = v[j][mid];
 						hi = mid - 1;
 					}
 					else lo = mid + 1;
 				}
 				mx = max(mx, last);
 			}

 			ans = min(ans, mx - i);
 			// if(i < 3001)cout << i << ' ' << ans << '\n';
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}