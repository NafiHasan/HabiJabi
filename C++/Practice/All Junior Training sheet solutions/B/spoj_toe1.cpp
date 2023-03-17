#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<bool>> vis(4, vector<bool>(4, 0));
vector<vector<char>> v(4, vector<char> (4));
bool val(int x, int y) {
	if (x < 1 || y < 1)return 0;
	if (x > 3 || y > 3)return 0;
	return 1;
}

void dfs(int px, int py, int x, int y) {
	if (x != -1 && y != -1 && v[px][py] != v[x][y])return;
	vis[x][y] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i == x && j == y)continue;
			if (!vis[i][j])dfs(x, y, i, j);
		}
	}
}


int main() {
	fast_io();
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)vis[i][j] = 0;
		}
		int cntx = 0, cnto = 0;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> v[i][j];
				if (v[i][j] == 'X')cntx++;
				else if (v[i][j] == 'O')cnto++;
			}
		}
		if (cntx < cnto) {
			cout << "no\n";
			continue;
		}
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i > 1 && j != 1)continue;
				if (j > 1 && i != 1)continue;
				if (v[i][j] != '.')dfs(-1, -1, i, j);
			}
		}
	}
	return 0;
}