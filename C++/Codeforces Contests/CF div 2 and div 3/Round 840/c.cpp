#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int> a(n);
 		int mx = 0;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			mx = max(mx, a[i]);
 		}
 		int ans = 0;
 		if(n == 2){
 			ans = max(a[0] + a[1], abs(a[0] - a[1]) * 2);
 		}
 		else {
 			if(n == 3){
 				int mm = max(a[0], max(a[1], a[2]));
 				int mn = min(a[0], min(a[1], a[2]));
 				mm -= mn;
 				if(a[0] == mx || a[n - 1] == mx){
 					ans = mx * n;
 				}
 				else {
 					sort(a.begin(), a.end());
 					ans = max(a[0] + a[1] + a[2], mm * 3);
 					ans = max(ans, (a[2] - a[0]) * 2 + a[1]);
 					ans = max(ans, a[1] * 3);
 				}
 			}
 			else ans = mx * n;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}