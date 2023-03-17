#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long



int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, x, y;
		cin >> n >> x >> y;
		vector<ll> a(n);
		for (int i = 0; i < n ; i++)cin >> a[i];
		ll lo = 0, hi = 1e10, mid, ans = LLONG_MAX;
		while (lo <= hi) {
			mid = (lo + hi) / 2LL;
			bool ok = 1;
			ll cnt = 0;
			vector<ll> tmp = a;
			for (int i = n - 1; i >= 0; i--) {
				tmp[i] -= cnt * y;
				if (tmp[i] <= 0)continue;
				ll mn = tmp[i] / y;
				if (tmp[i] % y != 0)mn++;
				ll mn2 = tmp[i] / x;
				if (tmp[i] % x != 0)mn2++;
				mn = min(mn, mn2);
				cnt += mn;
			}
			if (cnt > mid) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
				ans = min(ans, mid);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}