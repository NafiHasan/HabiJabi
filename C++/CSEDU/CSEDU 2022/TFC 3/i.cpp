#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main()
{
	fast_io();
 	ll a, b;
 	cin >> a>> b;
 	ll ans = LLONG_MAX;
 	if(b-a > 2020)ans = 0;
 	else {
 		for (ll i=a; i<b; i++){
 			for (ll j= a+1; j<=b; j++){
 				ans = min(ans, (i*j)%2019);
 			}
 		}
 	}
 	cout << ans << '\n';
    return 0;
}