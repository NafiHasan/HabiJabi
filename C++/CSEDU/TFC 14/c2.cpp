#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

const ll p=1e9+7;
ll fact[1000010], invfact[1000010];

long long bigmod(long long a, long long n){
	a %= p;
	long long ans=1;
	while(n){
		if(n&1) ans = ans * a % p;
		a = a * a % p;
		n>>=1;
	}
	return ans%p;
}
void factmodp(){
	fact[0]=1LL;
	for (ll i=1; i<1000005; i++)fact[i]=(fact[i-1]*i)%p;
}

void invfactmodp(){
	invfact[0]=1;
	for (ll i=1; i<1000005; i++)invfact[i]=bigmod(fact[i],p-2);
}

long long ncr(long long n, long long r){
	if (r == 0)return 1;
	long long ans = (fact[n] * invfact[r]) % p;
	ans= (ans * invfact[n-r]) % p;
	return ans % p ;
}

int main()
{
	fast_io();
	factmodp();
	invfactmodp();
 	w(t){
 		int n;
 		cin >> n;
 		// ll r=1e6+5;
 		// cout << r <<en <<1000005 << en;
 		// cout << ncr(10,2) << en;
 		ll num=n+1;
 		//cout << ncr(100000,1000) <<en;
 		ll ans=0;
 		for (ll i=0; i<n; i++){
 			ll a;
 			cin >> a;
 			ll cnt=ncr(num,i+1)-1;
 			cnt+=p;
 			cnt%=p;
 			a%=p;
 			ll x=cnt*a;
 			x+=p;
 			x%=p;
 			ans= ans + x;
 			ans%=p;
 		}
 		cout << ans <<en;
 	}	
    return 0;
}