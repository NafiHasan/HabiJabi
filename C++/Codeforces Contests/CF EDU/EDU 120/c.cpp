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
 		long long k;
 		cin >> n >> k;
 		vector<long long>a(n);
 		long long sum = 0;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			sum += a[i];
 		}
 		if(sum <= k){
 			cout << "0\n";
 			continue;
 		}
 		if(n == 1){
 			cout << max(0LL, a[0] - k) << '\n';
 			continue;
 		}
 		long long red = sum - k;
 		sort (a.begin(), a.end());
 		long long ans = LLONG_MAX;
 		if(a.back() - a[0] >= red) ans = 1;
 		ans = min (ans, red);
 		long long cnt = 2, pre = 0;
 		for (int i=n-1; i>0; i--){
 			pre += a[i];
 			long long tmp = a[0] + pre;
 			tmp = red - tmp;
			long long tt = tmp / cnt;
			if(tmp > 0 && tmp % cnt != 0)tt++;
			// else if(tmp <0 && tmp % cnt != 0)tt--;
			tt *= -1LL;
			if(tt > a[0]){
				ans = min(ans, cnt- 1);
			}
			else{
				long long mn = abs(a[0] - tt);
				mn += cnt - 1;
				// if(mn == 0) cout << tt << '\n';
				ans = min(ans, mn);
			}
 			cnt++ ;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}