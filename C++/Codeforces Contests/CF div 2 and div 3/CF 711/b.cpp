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
 		ll n,w;
 		cin >> n >>w;
 		map<ll,ll>a;
 		// vector<ll>a((1<<20)+1,0);
 		for (int i=0; i<n; i++){
 			ll x;
 			cin >> x;
 			a[x]++;
 		}
 		ll ans=0, tmp=w;
 		bool ok=1;
 		while(ok){
 			ok=0;
 			for (int i=1; i<=(1<<21); i*=2){
 				if(a[i]>0LL){
 					ok=1;
 					break;
 				}
 				//cout << a[i] <<" ";
 			}
 			if(!ok)break;
 			for (int i=(1<<21); i>=1; i/=2){
 				if(a[i]==0LL){
 					//i/=2;
 					continue;
 				}
 				if(i<=tmp){
 					ll cnt=min(a[i],tmp/i);
 					tmp-=i*cnt;
 					//cout << tmp << " ";
 					a[i]-=cnt;
 					//continue;
 				}
 			}
 			tmp=w;
 			ans++;
 		}
 		// for (int i=0; i<n ;i++){
 		// 	if(a[i]>tmp){
 		// 		ans++;
 		// 		tmp=w;
 		// 	}
 		// 	else tmp-=a[i];
 		// }
 		// ans++;
 		cout << ans << en;
 	}	
    return 0;
}