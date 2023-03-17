#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	fast_io();
	int n;
	cin >> n;
	vector<ll>a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	while (m--) {
		ll at, def;
		cin >> at >> def;
		ll ne = -1;
		ll ans = 0;
		int lo = 0, hi = n - 1, mid, ind;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (a[mid] >= at) {
				ne = a[mid];
				hi = mid - 1;
				ind = mid;
			} else {
				lo = mid + 1;
			}
		}
		if (ne == -1) {
			ans += max(0LL, at - a[n - 1]);
			ans += max(0LL, def - (sum - a[n - 1]));
		} else {
			ll temp;
			temp = max(0LL , def - (sum - ne));
			if (ind > 0) {
				ll an = max(0LL, at - a[ind - 1]);
				an += max(0LL, def - (sum - a[ind - 1]));
				temp = min(temp, an);
			}
			ans = temp;
		}
		cout << ans << '\n';
	}
	return 0;
}