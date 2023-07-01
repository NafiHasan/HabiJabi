#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	w(t){
 		ll n,k,ans=0;
 		cin >>n>>k;
 		ll a[n];
 		map<ll,ll>m;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			m[a[i]]++;
 			if (m[a[i]]==1)ans++;
 		}
 		sort (a,a+n);
 		ll mx=*max_element(a,a+n), mn=LLONG_MAX;
 		for (ll i=0; i<=n; i++){
 			if (m[i]==0){
 				mn=i;
 				break;
 			}
 		}

 		ll ad=mx+mn;
 		if (ad%2==0)ad/=2;
 		else {
 			ad/=2LL;
			ad++;
 		}
 		if (mn>a[n-1]){
 			ans+=k;
 		}
 		else if (m[ad]==0LL){
 			if (k)ans++;
 		}
 		cout <<ans<<en;
 	}
    return 0;
}