#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int mx = 0, mn = INT_MAX, mx2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			mn = min(mn, a[i]);
			mx2 = max(mx2, a[i]);
			mx = max(mx, a[i] - a[0]);
			mx = max(mx, a[n - 1] - a[i]);
			if (i < n - 1)mx = max(mx, a[i] - a[i + 1]);
		}
		int ans = mx;
		if (mx2 == a[n - 1]) {
			ans = max(ans, mx2 - mn);
		}
		cout << ans << '\n';
	}
	return 0;
}