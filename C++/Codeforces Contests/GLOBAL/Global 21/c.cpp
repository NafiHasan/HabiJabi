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
		vector<pair<ll, ll>> vp;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			ll last = 0, temp = x;
			while (temp % m == 0) {
				temp /= m;
			}
			pair<ll, ll> pa;
			if (x % m == 0) pa = {temp, x / temp};
			else pa = {x, 1};
			if (vp.size() > 0) {
				pair<ll, ll> topp = vp.back();
				if (topp.first == pa.first) {
					vp.back().second += pa.second;
				} else {
					vp.push_back(pa);
				}
			} else {
				vp.push_back(pa);
			}
		}
		// for (int i = 0; i < vp.size(); i++) {
		// 	cout << vp[i].first << ' ' << vp[i].second << '\n';
		// }
		ll k;
		cin >> k;
		vector<ll> b(k);
		bool ans = 1;
		for (int i = 0; i < k; i++)cin >> b[i];
		for (int i = k - 1; i >= 0; i--) {
			if (vp.size() == 0) {
				ans = 0;
				break;
			}
			pair<ll, ll> topp = vp.back();
			// if (topp.first != b[i] && b[i] % m != 0) {
			// 	ans = 0;
			// 	break;
			// } else
			if (topp.first == b[i]) {
				vp.back().second--;
			} else if (b[i] % topp.first == 0 && ((b[i] / topp.first) % m == 0) && topp.second >= (b[i] / topp.first)) {
				ll div = b[i] / topp.first;
				ll tmp = div;
				while (tmp % m == 0)tmp /= m;
				if (tmp != 1) {
					ans = 0;
					break;
				}
				if (div > topp.second) {
					ans = 0;
					break;
				} else {
					vp.back().second -= div;
				}
			} else {
				ans = 0;
				break;
			}
			if (vp.size() > 0 && vp.back().second == 0)vp.pop_back();
		}
		if (vp.size() > 0 )ans = 0;
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}