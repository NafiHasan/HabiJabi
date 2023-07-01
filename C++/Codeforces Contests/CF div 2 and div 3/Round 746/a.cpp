#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		ll n, h;
		cin >> n >>h;
		vector<ll>v(n);
		for (int i=0; i<n ;i++)cin >> v[i];
		sort (v.rbegin(), v.rend());
		ll ans =0;
		if(v[0] >= h){
			ans =1;
		}
		else {
			ll bar = h/(v[0]+v[1]);
			ans+=2LL*bar;
			h-= bar*(v[0]+v[1]);
			if(h > v[0])ans+=2;
			else if(h > 0 && h <= v[0])ans++;
		}
		cout << ans << '\n';
	}
    return 0;
}