#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int n, m, k, cnt = 0, g = 0;
vector<string> grid(505, "");
vector<vector<bool>> vis(505, vector<bool> (505, 0));

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool valid(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m)return 0;
	if (grid[r][c] == '#' || grid[r][c] == 'X')return 0;
	return 1;
}

void dfs(int r, int c) {
	cnt++;
	vis[r][c] = 1;
	// if (cnt >= k)return;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid(rr, cc) && !vis[rr][cc] && cnt < (g - k)) {
			dfs(rr, cc);
		}
	}
}



int main() {
	fast_io();
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)cin >> grid[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == '.')g++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				dfs(i, j);
				i = n;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.' && !vis[i][j])grid[i][j] = 'X';
		}
	}
	for (int i = 0; i < n; i++)cout << grid[i] << '\n';
	return 0;
}