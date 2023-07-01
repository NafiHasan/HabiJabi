#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int dr, dc, str, stc, i2, j2, n, m, bounce, ans;
string s;
vector<vector<vector<vector<int>>>> vis;

void dfs(int r, int c, int pr, int pc) {
	vis[r][c][dr + 1][dc + 1] = 1;
	// cout << r << ' ' << c << '\n';
	if (r == i2 && c == j2) {
		ans = bounce;
		return;
	}

	if (r == 1 || r == n || c == 1 || c == m) {
		if (r + dr > n || r + dr < 1 || c + dc > m || c + dc < 1)bounce++;
		if ((r == 1 || r == n) && (r + dr  < 1 || r + dr > n))
			dr *= -1;
		if ((c == 1 || c == m) && (c + dc  < 1 || c + dc > m))
			dc *= -1;
	}
	if (!vis[r + dr][c + dc][dr + 1][dc + 1])dfs(r + dr, c + dc, r, c);
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> str >> stc >> i2 >> j2 >> s;
		if (s == "DL")dr = 1, dc = -1;
		if (s == "DR")dr = 1, dc = 1;
		if (s == "UL")dr = -1, dc = -1;
		if (s == "UR")dr = -1, dc = 1;
		bounce = 0;
		ans = -1;
		vector<int> v(3, 0);
		vector<vector<int>> v2(3, v);
		vector<vector<vector<int>>> v3(m + 1, v2);
		vis.clear();
		vis.resize(n + 1, v3);
		dfs(str, stc, -1, -1);

		cout << ans << '\n';
	}
	return 0;
}