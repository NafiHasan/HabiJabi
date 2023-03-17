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
 		ll n;
 		cin >> n;
 		ll a[n];
 		vector<ll> v1,v2;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(i%2==0)v1.push_back(a[i]);
 			else v2.push_back(a[i]);
 		}
 		// sort (v1.begin(), v1.end());
 		// sort (v2.begin(), v2.end());
 		ll ans=0, mn1=LLONG_MAX, prev1=LLONG_MAX, prev2=LLONG_MAX,mn2=LLONG_MAX,cnt1=0,cnt2=0;
 		vector<ll>sum1(n+2,LLONG_MAX),sum2(n+2,LLONG_MAX);
 		int j1=-1,j2=-1;
 		for (ll i=0; i<v1.size(); i++){
 			if (v1[i]<mn1){
 				mn1=v1[i];
 				if ((cnt1+((n-i)*v1[i])) < prev1){
 					sum1[++j1]=cnt1+((n-i)*v1[i]);
 					prev1=sum1[j1];
 				}
 			}
 			cnt1+=v1[i];
 		}
 		//cout << sum1 <<en;
 		for (ll i=0; i<v2.size(); i++){
 			if (v2[i]<mn2){
 				mn2=v2[i];
 			}
 			if ((cnt2+((n-i)*v2[i])) <prev2){
 				sum2[++j2]=cnt2+((n-i)*v2[i]);
 				prev2=sum2[j2];
 			}
 			cnt2+=v2[i];
 		}
 		if (j1<j2){
 			ans+=sum1[j1];
 			//cout << j1 << " " << j2 <<" ";
 			ans+=min(sum2[j1+1],sum2[j1]);
 		}
 		else if (j2<j1){
 			ans+=sum2[j2];
 			//cout << " s";
 			ans+=min(sum1[j2+1],sum1[j2]);
 		}
 		else {
 			ans=sum1[j1]+sum2[j1];
 			// cout << ans << " ";
 			// ans=min(ans,min(sum1[j1-1]+sum2[j1],sum2[j1-1]+sum1[j1]));
 			// ans=min(ans,min(sum1[j1+1]+sum2[j1],sum2[j1+1]+sum1[j1]));
 		}
 		cout << ans << en;
 	}	
    return 0;
}