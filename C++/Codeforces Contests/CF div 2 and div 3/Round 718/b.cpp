#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>v(n);
		vector<int>all;
		int ans[n][m];
		memset(ans, -1, sizeof(ans));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				all.push_back(x);
				v[i].push_back(x);
			}
			sort(v[i].begin(), v[i].end());
		}
		sort(all.begin(), all.end());
		map<int, int>mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					if (mp[k] > 0)continue;
					if (v[i][j] == all[k]) {
						ans[i][k] = v[i][j];
						mp[k]++;
						v[i][j] = -1;
						break;
					}
				}
			}
			for (int j = 0; j < m; j++) {
				if (v[i][j] == -1)continue;
				for (int k = 0; k < m; k++) {
					if (ans[i][k] == -1) {
						ans[i][k] = v[i][j];
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << en;
		}
	}
	return 0;
}