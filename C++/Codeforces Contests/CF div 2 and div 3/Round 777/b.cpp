#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cnt[n][m];
		memset(cnt , 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			int tmp = 0, pre = -1;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1') {
					tmp++;
					if (pre == -1)pre = j;
				} else {
					if (pre != -1) {
						for (int k = pre; k < j; k++) {
							cnt[i][k] = tmp;
							tmp = 0;
							pre = -1;
						}
					}
				}
			}
			if (pre != -1) {
				for (int j = pre; j < m; j++) {
					cnt[i][j] = tmp;
				}
			}
		}
		bool ans = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1' && a[i - 1][j] == '1' && cnt[i - 1][j] != cnt[i][j]) {
					ans = 0;
					// cout << i << ' ' << j << '\n';
					// cout << cnt[i - 1][j] << ' ' << cnt[i][j] << '\n';
				}
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}