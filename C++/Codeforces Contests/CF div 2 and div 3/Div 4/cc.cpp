#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		ll ans = 0;
		sort(a.begin(), a.end());
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (x < a[i])break;
			ll tmp =  (x - a[i]) / (i + 1);
			// cout << tmp << '\n';
			ans += tmp  + 1;
			x -= a[i];
			// sum += a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}