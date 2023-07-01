#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		ll n, k;
 		cin >> n >> k;
 		vector<ll> a(n), ol(n);
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			// ol[i] = a[i]
 			a[i] = pow(10,a[i]);
 		}
 		ll ans = 0;
 		k++;
 		for (int i=0; i<n; i++){
 			if(k <= 0)break;
 			ll mn = k;
 			// if(k % a[i] != 0)mn++;
 			if(i < n-1)mn = min(mn, (a[i+1]-1)/a[i]);
 			// if(i == 0)mn--;
 			k -= mn;
 			ans += a[i] * mn;
 			// cout << mn << ' ';
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}