#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n >> m;
 		int inf = 1e9;
 		vector<vector<int>> grid(n, vector<int>(m));
 		vector<vector<int>> mn(n, vector<int>(m, inf));
 		vector<vector<int>> mx(n, vector<int>(m, 0));
 		for (int i=0; i<n; i++){
 			for (int j=0; j<m; j++)cin >> grid[i][j];
 		}
 		if((m + n) % 2 == 0){
 			cout << "NO\n";
 			continue;
 		}
 		mn[0][0] = grid[0][0];
 		mx[0][0] = grid[0][0];
 		for (int i=1; i<n; i++){
 			mn[i][0] = mn[i - 1][0] + grid[i][0];
 			mx[i][0] = mx[i - 1][0] + grid[i][0];
 		}
 		for (int i = 1; i<m; i++){
 			mn[0][i] = mn[0][i - 1] + grid[0][i];
 			mx[0][i] = mx[0][i - 1] + grid[0][i];
 		}
 		for (int i=1; i<n; i++){
 			for (int j=1; j<m; j++){
 					mn[i][j] = min(mn[i][j - 1] + grid[i][j] , mn[i - 1][j] + grid[i][j]);
 					mx[i][j] = max(mx[i][j - 1] + grid[i][j], mx[i - 1][j] + grid[i][j]);
 			}
 		}
 		if(mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}