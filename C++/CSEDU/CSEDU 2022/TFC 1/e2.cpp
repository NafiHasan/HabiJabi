#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int m, n;
 		cin >> m >> n;
 		vector<vector<int>>v,v2;
 		for (int i=0; i<m ;i++){
 			vector<int>tmp(n);
 			for (int j=0; j<n; j++){
 				cin >> tmp[j];
 			}
 			v2.push_back(tmp);
 			sort(tmp.rbegin(), tmp.rend());
 			v.push_back(tmp);
 		}
 		int ans = 0;
 		if(m < n){
 			vector<int>tmp(n,0);
 			for (int i=0; i<m; i++){
 				for (int j=0; j<n; j++){
 					tmp[j] = max(tmp[j], v2[i][j]);
 					// cout << i << ' ' << j << ' ' << v2[i][j] << ' ' << tmp [j] << '\n';
 				}
 				// cout << '\n';
 			}
 			// for (int i=0; i<n; i++)cout << tmp[i] << ' ';
 			ans = *min_element(tmp.begin(),tmp.end());
 		}
 		else {
 			for (int i=0; i<m; i++){
 				ans = max(ans,v[i][1]);
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}