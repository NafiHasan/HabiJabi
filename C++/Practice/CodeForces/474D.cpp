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
 	ll t, k;
 	cin >> t >> k;
 	vector<ll>dp(1000010,0LL);
 	dp[0]=1;
 	for (ll i=1; i<=100005; i++){
 		dp[i]=dp[i-1];
 		if(i>=k){
 			dp[i]+=dp[i-k];
 			dp[i] %= p;
 		}
 		//if(i<20)cout << dp[i] << " \n";
 	}
 	vector<ll>sum(1000010,0LL);
 	for (int i=1; i<=100008; i++){
 		sum[i]=dp[i]+sum[i-1];
 		sum[i]= (sum[i]+p) % p;
 	}
 	while(t--){
 		ll a, b;
 		cin >> a>> b;
 		ll ans = sum[b]-sum[a-1];
 		ans=(ans+p)%p;
 		cout << ans << en;
 	}
    return 0;
}