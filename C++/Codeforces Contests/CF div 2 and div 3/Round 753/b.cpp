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
 		ll x, n;
 		cin >> x >> n;
 		ll mod = n%4;
 		if(mod == 0){
 			cout << x << '\n';
 			continue;
 		}
 		ll now = n - mod +1;
 		ll pos = x;
 		// cout << now << ' ' << n << '\n';
 		for (ll i=now; i<=n; i++){
 			if(pos % 2 == 0)pos -= i;
 			else pos+= i;
 		}
 		cout << pos << '\n';
 	}	
    return 0;
}