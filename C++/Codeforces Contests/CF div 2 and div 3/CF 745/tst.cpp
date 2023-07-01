#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 #define ll long long
 	const int N = 3e5 + 10;
 	
 	ll fact[N], invfact[N];
 	
 	ll bigmod(ll a, ll n){
 		a %= mod;
 		ll ans=1;
 		while(n){
 			if(n&1) ans = ans * a % mod;
 			a = a * a % mod;
 			n >>= 1;
 		}
 		return ans % mod;
 	}
 	void factmodp() {
 		fact[0]=1LL;
 		for (ll i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % mod;
 	}
 	
 	void invfactmodp() {
 		invfact[0]=1;
 		for (ll i = 1; i < N; i++)invfact[i]=bigmod(fact[i],mod-2);
 	}
 	
 	ll ncr(ll n, ll r){
 		if (r == 0)return 1LL;
 		ll ans = (fact[n] * invfact[r]) % mod;
 		ans= (ans * invfact[n-r]) % mod;
 		return ans % mod ;
 	}	
    return 0;
}