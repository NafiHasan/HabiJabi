#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<long long, long long>> v;
		for (int i = 0; i < n; i++) {
			long long k;
			cin >> k;
			long long mx = 0;
			for (long long j = 0; j < k; j++) {
				long long now;
				cin >> now;
				mx = max(mx, now - j + 1);
			}
			v.push_back({mx, k});
			// cout << i << ' ' << mx << ' ' << k << '\n';
		}
		sort(v.begin(), v.end());
		long long ans = v[0].first, cur  = v[0].first + v[0].second;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].first > cur) {
				long long delta = v[i].first - cur;
				ans += delta;
				cur += delta;
				// ans = max(ans, v[i].first - i);
				// cur = v[i].first + v[i].second;
			}
			cur += v[i].second;
		}
		cout << ans << "\n";
	}
	return 0;
}