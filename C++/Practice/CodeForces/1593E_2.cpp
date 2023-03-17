#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		queue<int> q;
		vector<int> edge[n + 1], edge_cnt(n + 1, 0), depth(n + 1, 0);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			edge_cnt[u]++;
			edge_cnt[v]++;
		}
		for (int i = 1; i <= n; i++) {
			if (edge[i].size() == 1) {
				edge_cnt[i]--;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int t = q.front();
			q.pop();

			for (int i = 0; i < edge[t].size(); i++) {
				edge_cnt[edge[t][i]]--;
				if (edge_cnt[edge[t][i]] == 1) {
					q.push(edge[t][i]);
					depth[edge[t][i]] = depth[t] + 1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (depth[i] >= k)ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}