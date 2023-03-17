#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// dfs on a grid

const int N = 3005;
int n, m; // row, column

vector<string> grid(N);
vector<vector<bool>> vis(N, vector<bool> (N));
map<pair<int, int>, int> mp;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool valid(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m)return 0;
	if (grid[r][c] == '#')return 0; // checking block
	return 1;
}

void dfs(int r, int c) {
	cout << r << ' ' << c << '\n';
	vis[r][c] = 1;
	bool don = 0;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid(rr, cc) && !vis[rr][cc]) {
			don = 1;
			dfs(rr, cc);
		} else if (valid(rr, cc)) {
			don = 1;
		}
	}
	if (!don) {
		int cnt = 0;
		if (r > 0 && grid[r - 1][c] == '^')cnt++;
		if (c > 0 && grid[r][c - 1] == '^')cnt++;
		if (r < n - 1 && grid[r + 1][c] == '^')cnt++;
		if (c < m - 1 && grid[r][c + 1] == '^')cnt++;
		if (cnt < 2) {
			mp[ {r, c}] = 1;
			// cout << r << ' ' << c << '\n';
		}

	}
}

void clear_vis() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			vis[i][j] = 0;
}



int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		cin >> n >> m;
		mp.clear();
		clear_vis();
		for (int i = 0; i < n; i++)cin >> grid[i];
		pair<int, int> st = { -1, -1};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '^') {
					st = {i, j};
					i = n;
					break;
				}
			}
		}
		if (st.first == -1) {
			cout << "Possible\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)cout << grid[i][j];
				cout << '\n';
			}
			continue;
		}
		dfs(st.first, st.second);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[ {i, j}] == 0 && grid[i][j] != '#') {
					grid[i][j] = '^';
				}
				cout << grid[i][j];
			}
			cout << '\n';
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '.' || grid[i][j] == '#')continue;
				int cnt = 0;
				if (i > 0 && grid[i - 1][j] == '^')cnt++;
				if (j > 0 && grid[i][j - 1] == '^')cnt++;
				if (i < n - 1 && grid[i + 1][j] == '^')cnt++;
				if (j < m - 1 && grid[i][j + 1] == '^')cnt++;
				if (cnt < 2) {
					ok = 0;
					break;
				}
			}
		}
		if (!ok) {
			cout << "Impossible\n";
		} else {
			cout << "Possible\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << grid[i][j];
				}
				cout << '\n';
			}
		}
	}
	return 0;
}