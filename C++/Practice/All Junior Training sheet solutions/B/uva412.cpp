#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
ll ncr(ll n, ll r){
	if (r == 0)return 1;
	ll ans = 1;
	for (ll i=n, j = 1; i>(n-r), j<=min(n-r, r); i--, j++){
		ans *= i;
		ans /= j;
	}
	return ans;
}


int main()
{
	fast_io();
 	while(1){
 		ll n;
 		cin >> n;
 		if(n == 0)return 0;
 		vector<ll>a(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		ll cnt = 0;
 		for (int i=0; i<n-1; i++){
 			for (int j=i+1; j<n; j++)if(__gcd(a[i], a[j]) == 1)cnt++;
 		}
 		double ans = 6 * ncr(n, 2);
 		// cout << cnt << '\n';
 		if(cnt == 0){
 			cout<< "No estimate for this data set.\n";
 			continue;
 		}
 		ans /= cnt;
 		cout << fixed << setprecision(6) << sqrt(ans) << '\n';
 	}	
    return 0;
}