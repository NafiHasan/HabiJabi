#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		long long h;
 		cin >> n >> h;
 		vector<long long>a(n), sum(n), pre(n+1,0);
 		for (int i=0; i<n; i++)cin >> a[i];
 		for (int i=1; i<n; i++) sum[i-1] = min(h, a[i] - a[i-1]); 
 		sum[n-1] = h;
 		sort(sum.begin(), sum.end());
 		long long lo = 1, hi = h, mid, ans = h+1;
 		while(lo <= hi){
 			mid = (lo+hi)/2;
 			long long tmp =0, cnt =0;
 			for (int i=0; i<n; i++){
 				cnt = i;
 				if(sum[i] < mid) tmp+=sum[i];
 				else break;
 			}
 			tmp += (n-cnt)*mid;
 			if(tmp >= h){
 				ans = min(ans, mid);
 				hi = mid - 1;
 			}
 			else lo = mid + 1;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}