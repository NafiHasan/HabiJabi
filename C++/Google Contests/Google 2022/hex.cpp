#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 205;
vector<string> a(N);
bool vis[N][N];
int n;

int dr[] = { -1, -1, 0, 1, 1, 0};
int dc[] = { 0, 1, -1, -1, 0, 1};

bool valid(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= n)return 0;
	if (a[r][c] == '.')return 0;
	return 1;
}


void dfs(int r, int c) {
	vis[r][c] = 1;
	for (int i = 0; i < 6; i++) {
		int rr = r + dr[i] , cc = c + dc[i];
		if (valid(rr, cc) && a[r][c] == a[rr][cc] && !vis[rr][cc]) {
			dfs(rr, cc);
		}
	}
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		memset(vis, 0 , sizeof(vis));
		cout << "Case #" << cs << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		int cntb = 0, cntr = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'B')cntb++;
				else if (a[i][j] == 'R')cntr++;
			}
		}
		if (abs(cntb - cntr) > 1) {
			cout << "Impossible\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (a[i][0] == 'B' && !vis[i][0]) {
				dfs(i, 0);
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[0][i] == 'R' && !vis[0][i]) {
				dfs(0, i);
			}
		}

		int bl = 0, re = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][n - 1] == 'B' && vis[i][n - 1]) {
				bl++;
			}
			if (a[n - 1][i] == 'R' && vis[n - 1][i])re++;
		}
		if (bl >= 1 && re >= 1) {
			cout << "Impossible\n";
			continue;
		}
		if (bl >= 1 && cntb >= cntr) {
			bool ys = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] == 'B') {
						a[i][j] = '.';
						memset(vis, 0 , sizeof(vis));
						for (int ii = 0; ii < n; ii++) {
							if (a[ii][0] == 'B' && !vis[ii][0]) {
								dfs(ii, 0);
							}
						}
						int win = 0;
						for (int ii = 0; ii < n; ii++) {
							if (a[ii][n - 1] == 'B' && vis[ii][n - 1]) {
								win++;
							}
						}
						a[i][j] = 'B';
						if (win == 0) {
							ys = 1;
							i = n;
							break;
						}
					}
				}
			}
			if (ys)cout << "Blue wins\n";
			else cout << "Impossible\n";
			continue;
		}
		if (re >= 1 && cntr >= cntb) {
			bool ys = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] == 'R') {
						a[i][j] = '.';
						memset(vis, 0 , sizeof(vis));
						for (int ii = 0; ii < n; ii++) {
							if (a[0][ii] == 'R' && !vis[0][ii]) {
								dfs(0, ii);
							}
						}
						int win = 0;
						for (int ii = 0; ii < n; ii++) {
							if (a[n - 1][ii] == 'R' && vis[n - 1][ii])win++;
						}
						a[i][j] = 'R';
						if (win == 0) {
							ys = 1;
							i = n;
							break;
						}
					}
				}
			}
			if (ys)cout << "Red wins\n";
			else cout << "Impossible\n";
			continue;
		}
		if (bl + re == 0) {
			cout << "Nobody wins\n";
			continue;
		}
		cout << "Impossible\n";
	}
	return 0;
}