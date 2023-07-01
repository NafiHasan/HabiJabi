#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		deque<long long> d;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			d.push_back(x);
		}
		sort(d.begin(), d.end());
		vector<long long> presum(n + 1, 0);
		for (int i = 0; i < n; i++) {
			presum[i + 1] = presum[i] + d[i];
		}
		long long ans = 0;
		for (int l = 0, r; l <= k; l++) {
			r = k - l;
			long long cur = presum[n] - presum[2 * l] - (presum[n] - presum[n - r]);
			// cout << cur << '\n';
			ans = max(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}