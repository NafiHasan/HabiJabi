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
		vector<int> a(n), mn(n), mx(n);
		int mxx = 0, mnn = INT_MAX;
		// int mx = 0, mn = INT_MAX, lo, hi;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mxx = max(mxx, a[i]);
			mx[i] = mxx;
		}
		for (int i = n - 1; i >= 0; i--) {
			mnn = min(mnn, a[i]);
			mn[i] = mnn;
		}
		bool ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (mx[i] > mn[i]) {
				ans = 1;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}