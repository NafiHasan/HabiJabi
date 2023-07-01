#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n, k;
 		cin >> n >> k;
 		long long cnt = 1, now = 1, ans = 0;
 		while(cnt < n && now <= k){
 			cnt += now;
 			now *= 2LL;
 			ans++;
 		}
 		if(now > k && cnt < n){
 			n-= cnt;
 			ans += n/k;
 			if(n%k!= 0)ans++;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}