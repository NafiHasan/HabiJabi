#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 500;
vector<string> grid(N);
int n;

vector<string> all;
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(char ch, int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= n)return 0;
	if (grid[r][c] <= ch)return 0;
	return 1;
}


bool cmp(string a, string b) {
	if (a.size() != b.size())return a.size() < b.size();
	return a < b;
}
void dfs(int r, int c, string s) {
	// vis[r][c] = 1;
	s += grid[r][c];
	// cout << s << '\n';
	// cout << r << ' ' << c << '\n';
	if (s.size() >= 3)all.push_back(s);
	// vector<pair<char, pair<int, int>>> vp;
	for (int i = 0; i < 8; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		// if (r == 1 && c == 1)cout << rr << ' ' << cc << "rc\n";
		if (valid(grid[r][c], rr, cc)) {
			// vp.push_back({grid[rr][cc], {rr, cc}});
			dfs(rr, cc, s);
		}
	}
	// sort(vp.begin(), vp.end());
	// for (int i = 0; i < vp.size(); i++) {
	// 	dfs(vp[i].second.first, vp[i].second.second, s);
	// }
}


int main() {
	fast_io();
	int tc;
	int cs = 1;
	cin >> tc;
	while (tc--) {
		if (cs > 1) cout << "\n";
		cs++;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
		}
		all.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dfs(i, j, "");
			}
		}
		sort(all.begin(), all.end(), cmp);
		for (int i = 0; i < all.size(); i++) {
			// if (i)cout << "\n";
			if (i && all[i] != all[i - 1])cout << all[i] << '\n';
			else if (i == 0)cout << all[i] << "\n";
			// cout << "\n";
		}
	}
	return 0;
}