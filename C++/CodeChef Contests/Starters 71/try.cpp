#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin>> tc;
 	for (int cs = 1; cs<= tc; cs++){
 		cout << "Case " << cs << ": ";
 		int n, k;
 		cin >> n>> k;
 		vector<int> a(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		int ans = 0, lo = 1, hi = 1e18, mid;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			int now = 0, tot = 0;
 			for (int i=0; i<n; i++){
 				tot += min(a[i], mid);
 			}
 			now = tot/mid;
 			if(now >= k){
 				ans = max(ans, mid);
 				lo = mid + 1;
 			}
 			else hi = mid - 1;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}