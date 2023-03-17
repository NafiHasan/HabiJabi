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
 		}
 		ll cnt1=0,cnt2=0,sum1=0,sum2=0,mn1=LLONG_MAX,mn2=mn1;
 		ll ans=LLONG_MAX,x1,x2;
 		for (int i=0; i<n; i++){
 			if (i%2==0){
 				sum1+=a[i];
 				cnt1++;
 				mn1=min(mn1,a[i]);
 				x1= sum1+((n-cnt1)*mn1);
 			}
 			else {
 				sum2+=a[i];
 				cnt2++;
 				mn2=min(mn2,a[i]);
 				x2= sum2+((n-cnt2)*mn2);
 			}
 			//cout << x1 << " " << x2 << "\n ";
 			if (i)ans=min(ans,x1+x2);
 		}
 		cout << ans << en;
 	}	
    return 0;
}