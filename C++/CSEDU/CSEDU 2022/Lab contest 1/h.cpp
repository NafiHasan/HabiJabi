#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 55;
vector<string> grid(N);
vector<vector<bool>> vis(N, vector<bool> (N, 0)),
       vis2(N, vector<bool> (N, 0));

vector<pair<int, int>> vp;

int n, m;

int dr[] = { -1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= m)return 0;
	if (grid[r][c] == '.')return 0;
	return 1;
}

bool valid2(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= m)return 0;
	if (grid[r][c] != 'X')return 0;
	return 1;
}

void dfs(int r, int c) {
	vis[r][c] = 1;
	// if (r > 4 || c > 8) {
	// 	cout << "out" << r << ' ' << c << '\n';
	// 	return ;
	// }
	vp.push_back({r, c});

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid(rr, cc) && !vis[rr][cc]) {
			// if (rr >= n ) {
			// 	cout << "no";
			// 	break;
			// }
			dfs(rr, cc);
		}
	}
}

void dfs2(int r, int c) {
	vis2[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid2(rr, cc) && !vis2[rr][cc])dfs2(rr, cc);
	}
}


int main() {
	fast_io();
	int cs = 1;
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		// if (cs > 1)cout << "\n";

		for (int i = 0; i <= n ; i++) {
			for (int j = 0; j <= m; j++) {
				vis[i][j] = 0;
				vis2[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++)cin >> grid[i];
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vp.clear();
				if (grid[i][j] != '.') {
					// cout << "i j " << i << ' ' <<  j << '\n';
					dfs(i, j);
					int cnt = 0;
					// cout << "f";
					for (int k = 0; k < vp.size(); k++) {
						int rr = vp[k].first, cc = vp[k].second;
						// cout << rr << ' ' << cc << "\n";
						if (vis[rr][cc] && !vis2[rr][cc] && grid[rr][cc] == 'X') {
							cnt++;
							dfs2(rr, cc);
						}
					}
					if (cnt > 0)ans.push_back(cnt);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Throw " << cs++ << "\n";
		for (int i = 0; i < ans.size(); i++) {
			if (i)cout << " ";
			cout << ans[i];
		}
		cout << "\n\n";
	}
	return 0;
}