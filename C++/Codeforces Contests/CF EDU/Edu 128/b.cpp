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
		for (int i = 0; i < n; i++)cin >> a[i];
		vector<pair<int, int>> pos;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'R')pos.push_back({i, j});
			}
		}
		bool ans = 0;
		for (int i = 0; i < pos.size(); i++) {
			int up = pos[i].first, down = pos[i].second;
			bool brk = 0;
			for (int j = 0; j < pos.size(); j++) {
				if (i == j)continue;
				if (pos[j].first - up < 0 || pos[j].second - down < 0) {
					brk = 1;
					break;
				}
			}
			if (!brk) {
				ans = 1;
				break;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}