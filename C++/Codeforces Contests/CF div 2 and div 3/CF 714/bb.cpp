#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
const ll p= 1e9+7;
int main()
{
	fast_io();
 	ll fact[200005];
 	fact[0]=1;
 	for (ll i=1; i<200005; i++){
 		fact[i]=(i*fact[i-1])%p;
 	}
 	w(t){
 		ll n;
 		cin >> n;
 		map<ll,ll>m;
 		ll a[n];
 		for (int i=0; i<n; i++) {
 			cin >> a[i];
 			m[a[i]]++;
 		}
 		ll an=a[0];
 		for (ll i=1; i<n; i++)an &= a[i];
 		vector<ll>v;
 		map<ll,ll>put;
 		for(ll i=0 ; i<n; i++) {
 			if(m[a[i]]>1 && put[a[i]]==0){
 				v.push_back(a[i]);
 				put[a[i]]++;
 			}
 		}
 		ll ans=0;
 		for (ll i=0; i<v.size(); i++){
 			if((v[i] & an) == v[i]){
 				ll cnt=m[v[i]];
 				cnt*=(cnt-1);
 				ans += ((cnt % p)  * fact[n-2] ) % p;
 				ans = (ans+p) % p;
 			}
 		}
 		cout << ans << en;
 	}	
    return 0;
}