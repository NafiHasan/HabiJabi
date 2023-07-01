#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> edge[n + 1];
		map<pair<int, int>, int> mp, col;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			mp[ {u, v}] = i;
			mp[ {v, u}] = i;
		}
		string s(m, ' ');
		int r = m / 2, b = m - r;
		int leadr = 0;
		for (int i = 1; i <= n; i++) {
			int curr = 0, curb = 0;
			for (int j = 0; j < edge[i].size(); j++) {
				int u = i, v = edge[i][j];
				if (col[ {u, v}] != 0) {
					if (s[mp[ {u, v}]] == '1')curr++;
					else curb++;
					continue;
				}
				col[ {u, v}]++;
				col[ {v, u}]++;
				if (r >= b && leadr >= 0) {
					s[mp[ {u, v}]] = '1';
					curr++;
					r--;
				} else {
					s[mp[ {u, v}]] = '0';
					curb++;
					b--;
				}
			}
			if (curr > curb)leadr++;
			else if (curr < curb)leadr--;
		}
		cout << s << '\n';
	}
	return 0;
}