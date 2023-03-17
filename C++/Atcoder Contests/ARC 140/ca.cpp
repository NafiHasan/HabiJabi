#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N];
map<pair<int, int>, int> cost;
vector<bool> vis(N, 0);
vector<pair<int, int>> vp;
int cnt = 0;
int inf = 0;
void dfs(int u) {
	vis[u] = 1;
	inf++;
	for (int i : edge[u]) {
		if (cost[ {u, i}] == 1) {
			vp.push_back({u, i});
			continue;
		}
		if (!vis[i]) {
			dfs(i);
		}
	}
}

void dfs2(int u) {
	vis[u] = 1;
	cnt++;
	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs2(i);
		}
	}
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vp.clear();
		cost.clear();
		cnt = 0, inf = 0;
		for (int i = 0 ; i <= n; i++) {
			vis[i] = 0;
			edge[i].clear();

		}
		for (int i = 0 ; i < n - 1; i++) {
			int u, v, x;
			cin >> u >> v >> x;
			edge[u].push_back(v);
			edge[v].push_back(u);
			cost[ {u, v}] = x;
			cost[ {v, u}] = x;
		}
		dfs(1);
		if (inf > k) {
			cout << "-1\n";
			continue;
		}

		vector<int> tmp;
		for (int i = 0; i < vp.size(); i++) {
			cnt = 0;
			if (vis[vp[i].first] != 1) {
				dfs2(vp[i].first);
				tmp.push_back(cnt);
			}
			cnt = 0;
			if (vis[vp[i].second] != 1) {
				dfs2(vp[i].second);
				tmp.push_back(cnt);
			}
		}
		sort(tmp.rbegin(), tmp.rend());
		int ans = tmp.size();
		// cout << ans << ' ' << inf << '\n';
		while (inf <= k && !tmp.empty()) {
			int cn = tmp.back();
			inf += cn;
			if (inf > k)break;
			tmp.pop_back();
			ans--;
		}
		cout << ans << '\n';

	}
	return 0;
}