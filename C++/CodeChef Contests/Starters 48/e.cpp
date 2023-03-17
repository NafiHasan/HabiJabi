#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll rev(ll num) {
	ll mx = 0;
	for (ll i = 0; i < 40; i++) {
		if (((1LL << i) & num) != 0LL) {
			mx = max(mx, i + 1);
		}
	}
	ll ans = 0;
	for (ll i = 0; i < mx; i++) {
		if (((1LL << i ) & num) == 0LL) {
			ans ^= (1LL << i);
		}
	}
	return ans;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, s;
		cin >> n >> s;
		// cout << rev (8) << '\n';
		ll ans = s, lo = (s / n), hi = s, mid;
		while (lo <= hi) {
			mid = lo;
			ll total = mid + rev(mid);
			cout << lo << ' ' << total << '\n';
			ll divv;
			if (n > 2) {
				divv = (s - total) / (n - 2);
				if ((s - total) % (n - 2) != 0)divv++;
			}
			if (n == 2) {
				if (total < s) {
					lo++;
					continue;
				} else {
					ans = min(ans, mid);
					break;
				}
			} else if (n > 2 && (divv <= mid)) {
				ans = min(ans, mid);
				break;
			}
			lo++;
		}
		cout << ans << '\n';
	}
	return 0;
}