#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int m,n;
 		cin >> m >> n;
 		int a[m][n], dp[m][n];
 		map<pair<pair<int,int>,int>,int>mp;
 		map<pair<int,int>,int>cnt;
 		for (int i=0; i<m; i++){
 			for (int j=0; j<n; j++){
 				cin >> a[i][j];
 				if(j == 0){
 					dp[i][j] = a[i][j];
 					cnt[{i,j}]=1;
 				}
 			}
 		}
 		// i = row, j = col
 		for (int i=0; i<m; i++){
 			for (int j =1 ; j<n; j++){
 				for (int k=0; k<m; k++){
 					// if(mp[{{i,j},k}] > (n-1))break;
 					dp[i][j] = min(a[i][j], dp[k][j-1]);
 					if(mp[{{k,j-1},k}] == 0){
 						mp[{{k,j-1},k}]++;
 						cnt[{i,j}] = cnt[{k,j-1}] + 1;
 					}
 					else cnt[{i,j}] = cnt[{k,j-1}];
 				}
 				cout << dp[i][j] << ' ' ;
 				cout << '\n';
 			}
 			cout << '\n';
 		}
 		int ans = 0;
 		for (int i=0; i<m; i++){
 			if(cnt[{i,n-1}] < n)ans = max(ans,dp[i][n-1]);
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}