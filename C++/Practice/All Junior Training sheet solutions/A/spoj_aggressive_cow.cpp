#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, c;
 		cin >> n >> c;
 		vector<int>a(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		sort(a.begin(), a.end());
 		int mn = a[n-1] - a[0] + 1, mx = a[n-1] - a[0];
 		for (int i=1; i<n; i++){
 			mn = min(mn, a[i] - a[i-1]);
 		}
 		int mid, ans = 0;
 		while(mn <= mx){
 			mid = (mn + mx)/2;
 			// cout << mid << ' ';
 			bool ys = 1;
 			int cnt = 1;
 			int last = a[0];
 			int cur = INT_MAX;
 			while(cnt < c){
 				cnt++;
 				int now = last;
 				if(now + mid > a[n-1]){
 					ys = 0;
 					break;
 				}
 				int lo = 0, hi = n-1, midd;
 				while(lo <= hi){
 					midd = (lo + hi)/2;
 					if(a[midd] == now + mid){
 						last = a[midd];
 						break;
 					}
 					else if(a[midd] > now + mid){
 						last = a[midd];
 						hi = midd-1;
 					}
 					else lo = midd + 1;
 				}
 				cur = min(cur, last - now);
 			}
 			if(ys){
 				ans = max(ans, cur);
 				mn = mid + 1;
 			}
 			else mx = mid - 1;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}