#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();	
 	ll n , k, ans = 0;
 	cin >> n >> k;
 	vector<ll>a(n);
 	for (int i=0; i<n; i++)cin >> a[i];
 	for (int i=0; i<50; i++){
 		ll cnt0 = 0, cnt1 = 0;
 		for (int j=0; j<n; j++){
 			if(((1LL << i) & a[j]) == 0)cnt0++;
 			else {
 				cnt1++;
 				// cout << (1LL << i) << ' ' << a[j] << '\n';
 			}
 		}
 		// if(i < 5) cout << cnt0 << ' ' << cnt1 << '\n';
 		if(cnt1 < cnt0){
 			// cout << i << ' ' << cnt1 << ' '<< cnt0 << '\n';
 			ans |= (1LL << i);
 		}
 		// cout << ans << '\n';
 	}
 	ll last = -1;
 	for (ll i=0; i<64; i++){
 		if(((1LL << i) & k) > 0)last = i;
 	}
 	// cout << last << '\n';
 	for (ll i=last + 1; i<64; i++){
 		if(((1LL << i) & ans) > 0)ans ^= (1LL << i);
 	}
 	ll sum = 0;
 	// cout << last << '\n';
 	// cout << ans  << '\n';
 	if(ans > k){
 		for (ll i=last; i>=0; i--){
 			if(((1LL <<i ) & k ) > 0 && ((1LL << i) & ans) == 0 )break;
 			if(((1LL << i) & k) == 0 && ((1LL << i) & ans) > 0){
 				ans = ans ^ (1LL << i);
 				// cout << i << 'k' << '\n';
 			}
 		}
 	}
 	for (ll i =0; i<n; i++){
 		sum += (a[i] ^ ans);
 	}
 	// cout << ans  << '\n';
 	// for (int i=4; i<=8; i++)cout << (4 ^ i) << '\n';
 	cout << sum << '\n';
    return 0;
}