#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n , m;
 		cin >> n >> m;
 		vector<vector<int>> grid(n, vector<int> (m));
 		for (int i=0; i<n; i++){
 			for (int j=0; j<m; j++)cin >> grid[i][j];
 		}
 		map<pair<pair<int,int>,int>, int>mp;
 		if((m + n) % 2 == 0){
 			cout << "NO\n";
 			continue;
 		}
 		vector<int> a[n + 5][m + 5];
 		a[0][0].push_back(grid[0][0]);
 		for (int i=0; i<n; i++){
 			for (int j=0; j<m; j++){
 				if(i > 0){
 					for (int k=0; k<a[i - 1][j].size(); k++){
 						if(mp[{{i,j},grid[i][j] + a[i-1][j][k]}] == 0){
 						a[i][j].push_back(grid[i][j] + a[i-1][j][k]);
 						mp[{{i,j},grid[i][j] + a[i-1][j][k]}]++;
 					}
 					}
 				}
 				if(j > 0){
 					for (int k=0; k<a[i][j-1].size(); k++){
 						if(mp[{{i,j},grid[i][j] + a[i][j-1][k]}] == 0){
 							a[i][j].push_back(grid[i][j] + a[i][j-1][k]);
 							mp[{{i,j},grid[i][j] + a[i][j-1][k]}]++;
 						}
 					}
 				}
 			}
 		}

 		bool ans = 0;
 		for (int i=0; i<a[n - 1][m - 1].size(); i++){
 			if(a[n-1][m-1][i] == 0){
 				ans = 1;
 				break;
 			}
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}