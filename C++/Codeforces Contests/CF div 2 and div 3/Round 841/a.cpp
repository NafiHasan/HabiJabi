#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		ll n;
 		cin >> n;
 		vector<ll> a(n);
 		ll p = 1;
 		for (ll i=0; i<n; i++){
 			cin >> a[i];
 			p *= a[i];
 		}
 		ll ans= p + n - 1;
 		ans *= 2022L;
 		cout << ans << '\n';
 	}
    return 0;
}