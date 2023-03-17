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
		vector<ll> a(m);
		for (int i = 0; i < m ; i++)cin >> a[i];
		sort(a.begin(), a.end());
		vector<ll> dif;
		dif.push_back(a[0] - 1 + n - a[m - 1]);
		for (int i = 1; i < m; i++) {
			dif.push_back(a[i] - a[i - 1] - 1);
		}
		sort(dif.rbegin(), dif.rend());
		ll ans = 0, cum = 0;
		for (int i = 0; i < dif.size(); i++) {
			dif[i] -= cum;
			if (dif[i] > 0) {
				ans += max(1LL, dif[i] - 1);
			}
			cum += 4;
		}
		cout << (n - ans) << '\n';
	}
	return 0;
}