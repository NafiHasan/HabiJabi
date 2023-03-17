#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;
		vector<pair<ll, ll>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].second;
			a[i].first = a[i].second % m;
		}
		sort(a.begin(), a.end());
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll lo = i + 1, hi = n - 1, mid, ind = i, sm = a[i].first;
			while ( lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid].first >= sm) {
					ind = mid;
					hi = mid - 1;
				}
				//  else {
				// 	ind = mid;
				// 	lo = mid + 1;
				// }
			}
			// cout << a[i].second << ' ' << a[ind].second << '\n';
			ll md = (((a[i].second - a[ind].second) % m) + m) % m;
			ans = max(ans, a[i].second + a[ind].second + md);
			md = (((a[ind].second - a[i].second) % m) + m) % m;
			ans = max(ans, a[i].second + a[ind].second + md);
			lo = i + 1, hi = n - 1, ind = i, sm = a.back().first;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid].first <= sm) {
					ind = mid;
					lo = mid + 1;
				}
				//  else {
				// 	ind = mid;
				// 	hi = mid - 1;
				// }
			}
			// cout << a[i].second << ' ' << a[ind].second << '\n';
			md = (((a[i].second - a[ind].second) % m) + m) % m;
			ans = max(ans, a[i].second + a[ind].second + md);
			md = (((a[ind].second - a[i].second) % m) + m) % m;
			ans = max(ans, a[i].second + a[ind].second + md);
		}
		cout << ans << '\n';
	}
	return 0;
}