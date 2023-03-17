#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int n, m;
 	cin >> n >> m;
 	vector<string> a(n);
 	for (int i=0; i<n; i++)cin>> a[i];
 	int cnt[n + 2][n + 2];
 	memset(cnt, 0, sizeof cnt);
 	for (int i=0; i<n; i++){
 		for(int j=0; j<n; j++){
 			if(a[i][j] == 'O'){
 				cnt[i + 1][j + 1] = cnt[i + 1][j] + 1; 
 			}
 			else cnt[i + 1][j + 1] = cnt[i + 1][j];
 		}
 	}	
 	int q;
 	cin >> q;
 	while(q--){
 		int r, c;
 		cin >> r >> c;
 		int ans = 0;
 		for (int i=r, j = 0, k = m; i>=1 && j < m; i--, j++, k--){
 			int fs = c - (2 * k) + 1;
 			fs = max(1, fs);
 			ans += cnt[i][c] - cnt[i][fs - 1];
 		}
 		cout <<ans << '\n';
 	}
    return 0;
}