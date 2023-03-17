#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	ll n;
 	cin >> n;
 	vector<pair<ll,ll>>v1(n),v2(n);
 	map<pair<ll,ll>,ll>m;
 	for (int i=0; i<n; i++)cin >> v1[i].first ;	
 	for (int i=0; i<n; i++)cin >> v1[i].second ;
 	sort(v1.rbegin(), v1.rend());
 	ll ans=0LL;
 	for (int i=1; i<n; ){
 		if(i+1==n){
 			ans+=v1[i].second;
 			break;
 		}
 		else {
 			ans+=max(v1[i].second,v1[i+1].second);
 			i+=2;
 		}
 	}
 	ll ans2=0LL;
 	for (int i=n-1; i>(n/2); i--)ans2+=v1[i].second;
 	ans=max(ans,ans2);
 	ans2=0;
 	for (int i=1; i<n; i+=2)ans2+=v1[i].second;
 	ans=max(ans2,ans);
	cout << ans <<en;
    return 0;
}