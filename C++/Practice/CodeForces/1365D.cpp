#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 105;
int n, m;
vector<string> grid(N);
vector<vector<bool>> vis(N, vector<bool> (N));
vector<vector<bool>> mark(N, vector<bool> (N));

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool valid(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m)return 0;
	if (grid[r][c] == '#')return 0;
	return 1;
}

void dfs(int r, int c) {
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid(rr, cc) && !vis[rr][cc]) {
			if (grid[rr][cc] == 'G' && mark[rr][cc] == 1) {
				mark[r][c] = 1;
				return;
			} else dfs(rr, cc);
		}
	}
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)mark[i][j] = 0;
		}
		cin >> n >> m;
		int g = 0, b = 0;
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'G')g++;
				else if (grid[i][j] == 'B')b++;
			}
		}
		if (g == 0) {
			cout << "yes\n";
			continue;
		}
		bool ans = 1, run = 1;
		for (int i = 0; i < n && run; i++) {
			for (int j = 0; j < m && run; j++) {
				if (grid[i][j] == 'B') {
					// cout << i << ' ' << j << '\n';
					for (int k = 0; k < 4 && run; k++) {
						int rr = i + dr[k], cc = j + dc[k];
						// cout << rr << ' ' << cc << '\n';
						if (valid(rr, cc)) {
							if (grid[rr][cc] == 'G') {
								run = 0;
								ans = 0;
							} else if (grid[rr][cc] == '.') {
								grid[rr][cc] = '#';
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n && ans; i++) {
			for (int j = 0; j < m && ans; j++) {
				if (grid[i][j] == 'G' && mark[i][j] == 0) {
					for (int k = 0; k < n; k++) {
						for (int l = 0; l < m; l++) {
							vis[k][l] = 0;
						}
					}
					dfs(i, j);
					if (!vis[n - 1][m - 1])ans = 0;
					else {
						for (int k = 0; k < n; k++) {
							for (int l = 0; l < m; l++) {
								if (vis[k][l])mark[k][l] = 1;
							}
						}
					}
				}
			}
		}
		if (ans)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}