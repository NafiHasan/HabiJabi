#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1005;
vector<int> edge[N];
vector<vector<bool>> vis(N, vector<bool> (N, 0));

int cnt = 0, node = 0;

void dfs(int u) {
	node++;

	for (int i : edge[u]) {
		if (!vis[i][u]) {
			vis[i][u] = 1;
			dfs(i);
			cnt++;
		}
	}
}



int main() {
	FastIO;
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cnt = 0;
	dfs(1);
	cout << cnt << ' ' << node << '\n';
	if (cnt != node * (node - 1) / 2) {
		cout << "NO\n";
		return 0;
	}
	int un = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i][1] == 0) {
			un = i;
			break;
		}
	}
	if (un == 1) {
		cout << "YES\n";
		return 0;
	}
	cnt = 0, node = 0;
	dfs(un);
	if (cnt != node * (node - 1) / 2) {
		cout << "NO\n";
		return 0;
	} else {
		bool ok = 1;
		for (int i = 1; i <= n; i++)if (!vis[i][i])ok = 0;
		if (ok)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}