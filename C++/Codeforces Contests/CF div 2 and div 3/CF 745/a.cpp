#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
const ll mod = 1e9+7;
int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		ll n;
		cin >> n;
		ll ans = 1;
		for (ll i=2*n; i>2; i--){
			ans *= i;
			ans %= mod;
		}
		cout << ans << '\n';
	}	
    return 0;
}