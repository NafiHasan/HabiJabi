#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edge[n + 10];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
	}
	vector<int> vis(m + 10, 0);
	bool bad = false;
	for (int i = 1; i <= n; i++) {
		if ((int)edge[i].size() % 2 == 1) {
			bad = true;
			break;
		}
	}

	if (bad) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<int> st, ans;
	st.push_back(1);
	// ans.push_back(1);
	while (!st.empty()) {
		int v = -1;
		int i = st.back();
		while (!edge[i].empty()) {
			if (vis[edge[i].back().second] == 0) {
				v = edge[i].back().first;
				vis[edge[i].back().second]++;
				break;
			} else {
				edge[i].pop_back();
			}
		}

		if (v != -1) {
			st.push_back(v);
		} else {
			st.pop_back();
			ans.push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			if (vis[edge[i][j].second] == 0) {
				bad = 1;
				break;
			}
		}
	}
	if (bad) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i : ans)cout << i << ' ' ;
	puts("");
	return 0;
}
