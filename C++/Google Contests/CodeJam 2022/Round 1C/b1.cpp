#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1 ; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		ll n, k; cin >> n >> k;
		ll sum = 0, sq = 0;
		vector<ll> a(n);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			sq += a[i] * a[i];
		}
		ll ans = sq - (sum * sum);
		if (sum == 0 && sq != 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		} else if (sum == 0 && sq == 0) {
			cout << "1\n";
			continue;
		}
		if (ans % (2 * sum) != 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		ans /= (2 * sum);
		cout << ans << "\n";
	}
	return 0;
}