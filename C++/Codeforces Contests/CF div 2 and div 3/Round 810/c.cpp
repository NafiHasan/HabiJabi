#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m, k;
		cin >> n >> m >> k;
		vector<ll> a(k);
		for (int i = 0; i < k; i++)cin >> a[i];
		// sort(a.begin(), a.end());
		// ver
		bool ok = 0;
		if (m % 2 == 1) {
			ll chunk3 = 3 * n;
			ll chunk = 2 * n;
			ll allchunk = (m - 3) / 2;
			ll cnt = 0, cnt3 = 0;
			ll ind = 0, mn = chunk3 + 1;
			for (int i = 0; i < k; i++) {
				if (a[i] >= chunk3 && (a[i] % chunk3) < mn) {
					mn = a[i] % chunk3;
					ind = i;
				}
			}
			// cout << chunk << '\n';
			// cout << ind  << ' ' << chunk3 << '\n';
			for (int i = 0; i < k; i++) {
				if (i == ind && a[i] >= chunk3 && cnt3 == 0) {
					cnt3++;
					cnt += (a[i] - chunk3) / chunk;
					continue;
				}
				// cout << a[i] << " a " ;
				cnt += a[i] / chunk;
			}
			// cout << cnt << '\n';
			if (cnt >= allchunk && cnt3 >= 1)ok = 1;
			// cout << "1";
		} else if (m % 2 == 0) {
			ll chunk = 2 * n;
			ll allchunk = m / 2;
			ll cnt = 0;
			for (int i = 0; i < k; i++) {
				cnt += a[i] / chunk;
			}
			if (cnt >= allchunk)ok = 1;
			// cout << "2";
		}
		// hor
		if (n % 2 == 1) {
			ll chunk3 = 3 * m;
			ll chunk = 2 * m;
			ll allchunk = (n - 3) / 2;
			ll cnt = 0, cnt3 = 0;
			ll ind = 0, mn = chunk3 + 1;
			for (int i = 0; i < k; i++) {
				// cout << amn << ' ' << chunk3 << ' ' << (a[k] % chunk3) << '\n';
				if (a[i] >= chunk3 && (a[i] % chunk3) < mn) {
					mn = a[i] % chunk3;
					ind = i;
				}
			}
			for (int i = k - 1; i >= 0; i--) {
				if (i == ind && a[i] >= chunk3 && cnt3 == 0) {
					cnt3++;
					cnt += (a[i] - chunk3) / chunk;
					continue;
				}
				cnt += a[i] / chunk;
			}
			if (cnt >= allchunk && cnt3 >= 1)ok = 1;
			// cout << "3";
		} else if (n % 2 == 0) {
			ll chunk = 2 * m;
			ll allchunk = n / 2;
			ll cnt = 0;
			for (int i = 0; i < k; i++) {
				cnt += a[i] / chunk;
			}
			if (cnt >= allchunk)ok = 1;
			// cout << "4";
		}
		if (ok)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}