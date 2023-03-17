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
 		int flip = 0;
 		if(n < m){
 			swap(n, m);
 			flip = 1;
 		}
 		vector<int> a(n * m);
 		for (int i=0; i<n * m; i++)cin >> a[i];
 		sort(a.begin(), a.end());
 		int needmn = m/2;
 		int needmx = m - needmn - 1;
 		// cout << needmn << ' '  << needmx << '\n';
 		int st = 0, en = m * n - 1, best = INT_MAX, cur = 0;
 		int path = n + m  - 1;
 		for (int i=needmn; i< m*n - needmx && i + path - 1 < m * n; i++){
 			cur = a[i + path - 1] - a[i];
 			if(cur < best){
 				best = cur;
 				st = i, en = i + path - 1;
 			}
 		}
 		// cout << st << ' '<< en << '\n';
 		int tst = st;
 		vector<vector<int>> ans(n, vector<int> (m, -1));
 		int ind = 0;
 		for (int i=0; i<m; i++){
 			ans[0][i] = a[tst];
 			a[tst] = -1;
 			tst++;
 		}
 		for (int i=1; i<n; i++){
 			ans[i][m - 1] = a[tst];
 			a[tst] = -1;
 			tst++; 
 		}

 		for (int i=0, j = 0, k = m* n - 1; i<m-1; i++){
 			if(i % 2 == 0){
 				ans[1][i] = a[j++];
 				a[j -1] = -1;
 			}
 			else {
 				ans[1][i] = a[k--];
 				a[k + 1] = -1;
 			}
 		}
 		vector<int> uns;
 		for (int i=0; i<n * m; i++){
 			// if(i >= st && i <= en)continue;
 			if(a[i] != -1)uns.push_back(a[i]);
 		}
 		ind = 0;

 		// cout << uns.size() << '\n';
 		for (int i=0; i<n ;i++){
 			for (int j=0; j<m; j++){
 				if(ans[i][j] == -1){
 					ans[i][j] = uns[ind++];
 				}
 			}
 		}

 		// print
 		if(flip){
 			for (int i=0; i<m; i++){
 				for (int j=0; j<n; j++){
 					cout << ans[j][i] << ' ';
 				}
 				cout << '\n';
 			}
 		}
 		else {
 			for (int i=0; i<n; i++){
 				for (int j=0; j<m ;j++){
 					cout << ans[i][j] << ' ';
 				}
 				cout << '\n';
 			}
 		}
 	}	
    return 0;
}