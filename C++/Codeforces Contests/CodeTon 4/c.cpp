#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long


int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, c, d;
		cin >> n >> c >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		int cnt = 0, ans = LLONG_MAX, baad = 0;
		for (int i = 0; i < n; i++) {
			if (i && a[i] == a[i - 1]) {
				baad++;
				continue;
			}
			cnt++;
			int rem = a[i] - cnt;
			int tmp = rem * d + (n - i - 1 + baad) * c;
			// cout << tmp << '\n';
			ans = min(ans, tmp);
		}
		ans = min(ans, n * c + d);
		cout << ans << '\n';
	}
	return 0;
}