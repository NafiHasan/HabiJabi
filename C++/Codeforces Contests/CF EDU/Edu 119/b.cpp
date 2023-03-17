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
		ll w,h;
		cin >> w >> h;
		ll mx1 = 0;
		ll k1, fir, las, k2;
		cin >> k1;
		for (int i=0; i<k1; i++){
			ll x;
			cin >> x;
			if(i == 0)fir = x;
			else if(i == k1-1) las = x; 
		}
		mx1 = max(mx1, las - fir);
		cin >> k2;
		for (int i=0; i<k2; i++){
			ll x;
			cin >> x;
			if(i == 0)fir = x;
			else if(i == k2-1) las = x; 
		}
		mx1 = max(mx1, las - fir);
		ll ans = mx1 * h;
		ll k3,k4;
		cin >> k3;
		for (int i=0; i<k3; i++){
			ll x;
			cin >> x;
			if(i == 0)fir = x;
			else if(i == k3-1)las = x;
		}
		mx1 = las - fir;
		cin >> k4;
		for (int i=0; i<k4; i++){
			ll x;
			cin >> x;
			if(i == 0)fir = x;
			else if(i == k4-1)las = x;
		}
		mx1 = max(mx1 , las - fir);
		ans =max(ans, mx1*w);
		cout << ans << '\n';
	}	
    return 0;
}