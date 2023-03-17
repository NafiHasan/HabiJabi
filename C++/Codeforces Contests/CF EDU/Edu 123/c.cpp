#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, add;
		cin >> n >> add;
		vector<ll> a(n), cs(n + 1, 0);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++) {
			cs[i + 1] = cs[i] + a[i];
		}
		// for (int i = 0; i <= n; i++)cout << cs[i] << ' ';
		vector<ll> mx(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			ll best = LLONG_MIN;
			for (int j = 1; j <= n; j++) {
				if (j >= i)best = max(best, cs[j] - cs[j - i]);
			}
			mx[i] = best;
			// cout << best << '\n';
		}
		vector<ll> ans(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			ll best = 0;
			for (int j = 0; j <= n; j++) {
				ll ti = min(j, i);
				best = max(best , mx[j] + add * ti);
			}
			ans[i] = best;
		}
		for (int i = 0; i <= n; i++)cout << ans[i] << ' ';
		cout << "\n";
	}
	return 0;
}