#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int inf = 1e9;
	int ans = 1e9;
	bool vis[45][45];
	int m, n;
	int Grid[45][45];

	int dr[4] = {0, 1, 0, -1};
	int dc[4] = {1, 0, -1, 0};

	bool valid(int r, int c) {
		if (r < 0 || r >= m || c < 0 || c >= n)return 0;
		// if (grid[r][c] == )return 0; // checking block
		return 1;
	}

	void dfs(int r, int c, int dis, int k) {
		// cout << r << ' ' << c << ' ' << k <<  '\n';
		vis[r][c] = 1;

		if (r == m - 1 && c == n - 1) {
			ans = min(ans, dis);
			return ;
		}
		if (m - 1 - r + n - 1 - c)

			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i], cc = c + dc[i];
				if (valid(rr, cc) && !vis[rr][cc]) {
					cout << r << ' ' << c << ' '  << rr << ' ' << cc << '\n';
					if (Grid[rr][cc] == 1 && k > 0) dfs(rr, cc, dis + 1, k - 1);
					if (Grid[rr][cc] == 0)dfs(rr, cc, dis + 1, k);
				}
			}
	}

	int shortestPath(vector<vector<int>>& grid, int k) {
		m = grid.size();
		n = grid[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				Grid[i][j] = grid[i][j];
				vis[i][j] = 0;
			}
		}
		dfs(0, 0, 0, k);
		if (ans == inf) ans = -1;
		return ans;
	}
};


int main() {
	Solution s;
	vector<vector<int>> v(5, vector<int> (3, 0));
	v[1][0] = v[1][1] = v[3][1] = v[3][2] = 1;
	int ans = s.shortestPath(v, 1);
	cout << ans << '\n';
	cout << "FF";
	queue<vector<int>> q;

}

