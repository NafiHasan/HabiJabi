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
		if (a[0][0] == '1') {
			cout << "-1\n";
			continue;
		}
		vector<pair<pair<int, int>, pair<int, int>>>ans;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (a[i][j] == '1') {
					if (j > 0) {
						ans.push_back({{i + 1, j}, {i + 1 , j + 1}});
					} else ans.push_back({{i, j + 1}, {i + 1, j + 1}});
				}
			}
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first.first << ' ' << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
		}
	}
	return 0;
}