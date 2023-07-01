#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

const ll p=1e9+7;
int main()
{
	fast_io();
 	ll dp[200025];
	for (int i=0; i<10; i++)dp[i]=1;
	for (int i=10; i<200025; i++) dp[i]=(dp[i-10]+dp[i-9]) % p;
 	w(t){
 		ll n,m;
 		cin >> n>>m;
 		ll ans=0;
 		while(n){
 			ll tmp=n%10;
 			n/=10;
 			ans+=dp[tmp+m];
 			ans%=p;
 		}
 		cout << ans <<en;
 	}	
    return 0;
}