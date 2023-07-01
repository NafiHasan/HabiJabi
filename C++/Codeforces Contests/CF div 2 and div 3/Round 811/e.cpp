#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<ll> a[n];
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			a[i].push_back(x);
			for (int j = 1; j < 9; j++) {
				x += x % 10;
				a[i].push_back(x);
			}
			mx = max(mx, x);
		}
		// cout << mx << '\n';
		bool ans = 1;
		for (int i = 0; i < n ; i++) {
			bool f = 0;
			for (int j = 0; j < a[i].size(); j++) {
				if (a[i][j] == mx) {
					f = 1;
					break;
				}
				// cout << a[i][j] << ' ';
				ll ab = abs(a[i][j] - mx);
				if (a[i][j] != mx && a[i][j] % 10 == 0)continue;
				if (ab % 20 == 0) {
					f = 1;
					break;
				}
			}
			// cout << '\n';
			if (!f) {
				ans = 0;
				break;
			}
		}
		if (ans)cout << "YES\n";
		else cout  << "NO\n";
	}
	return 0;
}