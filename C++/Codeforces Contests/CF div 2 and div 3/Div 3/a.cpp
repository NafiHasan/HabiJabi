#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		ll n, m , x;
 		cin >> n >> m >> x;
 		ll a=x%n , b=x/n;
 		if(a==0)a=n;
 		if(x%n)b++;
 		ll ans=(a-1)*m+b;
 		cout << ans << en;
 	}
    return 0;
}