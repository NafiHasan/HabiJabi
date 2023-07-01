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
 		ll n;
 		cin >> n;
 		vector<ll>v;
 		for (ll i=1; i<=100000; i++){
 			v.push_back(i*i);
 		}
 		ll ans = sqrt(n);
 		ans += cbrt(n);
 		ll cnt = 0;
 		cnt = sqrt(n);
 		cnt = cbrt(cnt);
 		ans-= cnt;
 		cout << ans << '\n';
 	}	
    return 0;
}