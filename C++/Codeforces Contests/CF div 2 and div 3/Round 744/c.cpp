#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string>v(n);
		int ans[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) ans[i][j] = 0;
		}
		for (int i = 0; i < n; i++)cin >> v[i];
		for (int i = n - 1; i >= k; i--) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*') {
					int h = 0;
					for (int l = 1; ; l++) {
						if (i - l < 0 || j - l < 0 || j + l >= m)break;
						if (v[i - l][j - l] != '*' || v[i - l][j + l] != '*')break;
						h++;
					}
					// cout << h << '\n';
					if (h >= k ) {
						// cout << i << ' ' << j << '\n';
						for (int l = 0; ; l++) {
							if (i - l < 0 || j - l < 0 || j + l >= m)break;
							if (v[i - l][j - l] != '*' || v[i - l][j + l] != '*')break;
							ans[i - l][j - l] = 1;
							ans[i - l][j + l] = 1;
							// cout << i - l << ' ' << j - l << "a\n";
						}
					}
				}
			}
		}
		bool ys = 1;
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*' && ans[i][j] == 0) {
					ys = 0;
					// cout << i << ' ' << j << '\n';
				}
			}
		}
		if (ys)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}