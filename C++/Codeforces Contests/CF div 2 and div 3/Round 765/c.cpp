#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();
 	ll n, l, k;
 	cin>> n >> l >> k;
 	vector<ll>d(n+1), sp(n);
 	map<ll,ll>cnt;
 	for (int i=0; i<n; i++)cin >> d[i];
 	d[n] = l;
 	for (int i = 0; i < n; i++)cin >> sp[i];
 	int last = 0;
 	while(k--){
 		ll ind = -1, best = 0; 
 		int last = 0;
 		for(int i=2; i<=n; i++){
 			if(sp[i-1] != sp[i-1])last = i-1;
 			ll tmp = (d[i] - d[i-1]) * sp[i-1];
 			tmp += (d[i-1] - d[i-2]) * sp[i-2];
 			tmp -= (d[i] - d[i-2]) * sp[i-2];
 			if(tmp > best && cnt[i-1] == 0){
 				best = tmp;
 				ind  = i-1;
 			}
 		}
 		cnt[ind]++;
 		cout << ind << '\n';
		if(ind != -1){
			sp[ind] = sp[ind-1];
		}
 	}
 	ll ans = 0;
 	for(int i=1; i<=n; i++){
 		cout << sp[i -1 ] << ' ' ;
 		// cout << (d[i] - d[i-1]) * sp[i-1] << '\n';
 		ans += (d[i] - d[i-1]) * sp[i-1]; 
 	}
 	cout << ans << '\n';
    return 0;
}