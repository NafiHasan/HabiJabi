#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		ll all = n * (n + 1) / 2LL;
		bool ok = 1;
		if (sum % all != 0)ok = 0;
		ll tmp = sum / all;
		vector<ll> ans(n, 0);
		for (int i = 0; i < n && ok; i++) {
			int pre = i - 1;
			if (i == 0) pre = n - 1;
			ll cal = tmp + (a[pre] - a[i]);
			if (cal <= 0 || cal % n != 0)ok = 0;
			ans[i] = cal / n;
		}
		if (ok) {
			cout << "YES\n";
			for (ll i : ans)cout << i << ' ';
			cout << "\n";
		} else cout << "NO\n";
	}
	return 0;
}