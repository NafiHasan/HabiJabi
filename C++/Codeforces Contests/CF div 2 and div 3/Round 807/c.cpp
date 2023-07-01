#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll f(ll k, vector<pair<ll, ll>> presum, ll cs, vector<pair<pair<ll, ll>, ll>> vp) {
	ll lo = 0, hi = cs, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		// cout << mid << ' ' << cs << '\n';;
		if (k <= presum[mid].second && k >= presum[mid].first) {
			break;
		} else if (k > presum[mid].second)lo = mid + 1;
		else hi = mid - 1;
	}
	// if (k == 10 )cout << mid << '\n';
	if (mid == 0) {
		return k - presum[mid].first;
	} else return vp[mid - 1].first.first + k - presum[mid].first;
	// return 1;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, c, q;
		cin >> n >> c >> q;
		string s;
		cin >> s;
		vector<pair<pair<ll, ll>, ll>> vp(c);
		for (int i = 0; i < c; i++) {
			cin >> vp[i].first.first >> vp[i].first.second;
			vp[i].second = vp[i].first.second - vp[i].first.first + 1;
		}
		vector<pair<ll, ll>> presum(c + 2, {0, 0});
		presum[0].first = 1, presum[0].second = n;
		for (int i = 1; i <= c; i++) {
			presum[i].first = presum[i - 1].second + 1;
			presum[i].second = presum[i].first + vp[i - 1].second - 1;
		}
		// for (int i = 0; i <= c; i++) {
		// 	cout << presum[i].first << ' ' << presum[i].second << '\n';
		// }
		while (q--) {
			ll k;
			cin >> k;
			while (k > n) {
				k = f(k, presum, c, vp);
				// cout << k << '\n';
			}
			cout << s[k - 1] << '\n';
			// cout << k << '\n';
		}

	}

	return 0;
}