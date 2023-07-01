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
 	w(t){
 		ll n, k;
 		cin >> n >>k;
 		ll sum=n-1, ans=0;
 		vector<ll>dp(n-1,1LL);
 		for (int i=0; i<k-2; i++){
 			ll tmp=sum; tmp%=p;
 			sum=0;
 			vector<ll>tm(n-1,1LL);
 			for (int j=0,l=n-1; j<n-1; l--,j++){
 				ll a;
 				if(j==0)a=tmp;
 				else {
 					if(dp[l]<0)dp[l]+=p;
 					a=(tm[j-1]%p)-(dp[l]%p);
 					if(a<0)a+=p;
 				}
 				a%=p;
 				sum+=a; sum%=p;
 				ans+=a; ans%=p;
 				tm[j]=a;
 			}
 			dp=tm;
 		}
 		if(k==1)cout << "1\n";
 		else cout << ans+1+n << en;
 	}	
    return 0;
}