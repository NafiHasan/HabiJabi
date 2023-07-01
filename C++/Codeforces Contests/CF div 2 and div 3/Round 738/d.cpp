#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<bool>vis(1005, 0), vis2(1005, 0);
vector<int>edge1[1005], edge2[1005];

void dfs(int ser, int u) {
	if (ser == 1 ) {
		if (vis[u])return;
		vis[u] = 1;
		for (int i = 0; i < edge1[u].size(); i++)dfs(1, edge1[u][i]);
	} else {
		if (vis2[u])return;
		vis2[u] = 1;
		for (int i = 0; i < edge2[u].size(); i++)dfs(2, edge2[u][i]);
	}
	return ;
}


int main() {
	fast_io();
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}
	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge2[u].push_back(v);
		edge2[v].push_back(u);
	}
	vector<int>ans, free(n, 0), free2(n, 0);
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			dfs(1, i);
			dfs(2, i);
			if (vis[j] == 0 && vis2[j] == 0) {
				edge1[i].push_back(j);
				edge2[j].push_back(i);
				ans.push_back(i + 1);
				ans.push_back(j + 1);
			}
		}
		if (vis[i] || vis2[i])continue;
		dfs(1, i);
		if (vis2[i])continue;
		dfs(2, i);
		// cout << i << 'a';
		free[i]++;
	}
	// vis.clear();
	// for (int i=0; i<n; i++){
	// 	if(vis[i])continue;
	// 	dfs(2,i);
	// }

	for (int i = 0; i < n; i++)if (free[i] > 0)ans.push_back(i + 1);
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0 && vis2[i] == 0 && free[i] == 0) {
			ans.push_back(i + 1);
		}
	}
	cout << (ans.size() - 1) << "\n";
	for (int i = 1; i < ans.size(); i++)cout << ans[i] << " " << ans[i - 1] << "\n";
	return 0;
}