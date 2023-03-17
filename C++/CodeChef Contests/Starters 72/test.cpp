#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod=1e9+7;
const int N = 2e5 + 10;
vector<ll>fact(N), inv(N);

ll binpow(ll a, ll n){
	a %= mod;
	ll ans=1;
	while(n){
		if(n&1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans%mod;
}

int main() {
	FastIO;
	ll p = 9LL * binpow(3, mod - 2) % mod; 	
	cout << p ;
    return 0;
}