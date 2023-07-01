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
		vector<int> a[n + 1], ans(n + 1, 0);
		int mn = n + 1, mx = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mn = min(mn, x);
			mx = max(mx, x);
			a[x].push_back(i);
		}
		for (int i = mn; i <= mx; i++) {
			if (a[i].size() == 0)continue;
			int cur = 1;
			int pre = a[i][0];
			int ind = n + 1;
			for (int j = 1; j < a[i].size(); j++) {
				// cout << i << ' ' << a[i][j - 1] << '\n';
				if ((a[i][j] - pre) % 2 == 1) {
					cur++;
					pre = a[i][j];
				} else {
					if (ind == n + 1) ind = j;
				}
			}
			ans[i] = max(ans[i], cur);
			if (ind != n + 1)pre = a[i][ind];
			cur = 1;
			for (int j = ind + 1; j < a[i].size(); j++) {
				if ((a[i][j] - pre) % 2 == 1) {
					cur++;
					pre = a[i][j];
				}
			}
			ans[i] = max(ans[i], cur);
			if (a[i].size() == 0) {
				ans[i] = 0;
			}
		}
		for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}