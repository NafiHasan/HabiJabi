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
		vector<int> a(n), ti(n);
		int mx = 0, ind = -1, indd = -1;
		for (int i = 0; i < n ; i++)cin >> a[i];
		for (int i = 0; i < n ; i++) {
			cin >> ti[i];
			if (mx < ti[i]) {
				mx = ti[i];
				ind = a[i];
			}
		}
		int mxx = 0, mn = INT_MAX;
		// for (int i = 0; i < n; i++) {
		// 	mn = min(mn, )
		// 	mxx = max(mxx, a[i]);
		// 	mn = min(mn, a[i]);
		// }
		// int mn = INT_MAX, mxx = 0;
		for (int i = 0; i < n; i++) {
			int bon = mx - ti[i];
			mn = min(mn, a[i] + bon);
			mxx = max(mxx, a[i] - bon);
			// cout << mn << ' ' << mxx << '\n';
			// if (a[i] < mxx) {
			// 	a[i] = min(a[i] + bon, mxx);
			// 	mxx = min(mxx, a[i]);
			// } else if (a[i] > mn) {
			// 	a[i] = max(mn, a[i] - bon);
			// 	mn = max(mn, a[i]);
			// }
		}
		// for (int i = 0; i < n; i++)cout << a[i] << ' ';
		// cout << '\n';
		// if (mn == INT_MAX)mn = 0;
		// cout << mn << ' ' << mxx << '\n';
		// mn = *min_element(a.begin(), a.end());
		// mxx = *max_element(a.begin(), a.end());
		double ans = (mn + mxx) / 2.0;
		// if (mn > mx)ans = mx;
		cout << ans << '\n';
	}
	return 0;
}