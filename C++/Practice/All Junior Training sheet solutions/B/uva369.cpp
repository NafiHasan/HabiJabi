#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

// const ll mod = 1e9 + 7;
// const int N = 2e3 + 10;
// vector<ll>fact(N), invfact(N);

// ll bigmod(ll a, ll n){
// 	a %= mod;
// 	ll ans=1;
// 	while(n){
// 		if(n&1) ans = ans * a % mod;
// 		a = a * a % mod;
// 		n>>=1;
// 	}
// 	return ans%mod;
// }
// void factmodp(){
// 	fact[0]=1LL;
// 	for (ll i=1; i<N; i++)fact[i]=(fact[i-1]*i)%mod;
// }

// void invfactmodp(){
// 	invfact[0]=1;
// 	for (ll i=1; i<N; i++)invfact[i]=bigmod(fact[i],mod-2);
// }

ll ncr(ll n, ll r){
	if (r == 0)return 1;
	ll ans = 1;
	ll lim = max(n-r, r);
	for (ll i=n, j = 1; i>(n-r), j<=min(n-r, r); i--, j++){
		ans *= i;
		ans /= j;
	}
	return ans;
}


int main()
{
	// fast_io();
	// factmodp();
	// invfactmodp();
	double st = clock();
 	while(1){
 		ll n, m;
 		cin >> n >> m;
 		if(n == 0 && m == 0)return 0;
 		// cout << n <<  " things taken "<< m << " at a time is " << ncr(n,m) << " exactly.\n" ;
 	}
 	double en = clock();
 	cout << (en - st);
    return 0;
}