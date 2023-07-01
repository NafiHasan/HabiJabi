#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 2005;
vector<int> edge[N];
int Par[N];
// vector<bool> vis(N, 0);
int vis[N];

int root;
bool exist;
vector<pair<int, int>> lists;
void dfs(int u, int par) {
	vis[u] = 1;
	// cout << u << ' ' << par << '\n';
	for (int v : edge[u]) {
		if (vis[v] == 0) {
			// lists.push_back({u, v});
			Par[v] = u;
			// lists.push_back({u, v});
			dfs(v, u);
		} else if (vis[v] == 1 && v == root && v != par) {
			exist = 1;
			// lists.push_back({u, v});
			// lists.push_back({u, v});
			int cur = u;
			while (cur != v) {
				lists.push_back({cur, Par[cur]});
				cur = Par[cur];
			}
			lists.push_back({v, u});
			// return;
		}
	}
	vis[u] = 2;
	// if (u != root) {
	// 	lists.pop_back();
	// 	cout << u << '\n';
	// }
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n ; i++) {
			edge[i].clear();
			vis[i] = 0;
		}

		for (int i = 1; i <= m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		bool found = 0;
		for (int i = 1; i <= n && !found; i++) {
			if (edge[i].size() < 4)continue;
			for (int j = 0; j < edge[i].size() && !found; j++) {
				for (int k = j + 1; k < edge[i].size() && !found; k++) {
					memset(vis, 0, sizeof(vis));
					memset(Par, -1, sizeof(Par));
					lists.clear();
					lists.push_back({i, edge[i][j]});
					lists.push_back({i, edge[i][k]});
					vis[edge[i][j]] = 2;
					vis[edge[i][k]] = 2;
					root = i;
					// cout << "par " << i << ' ' << edge[i][j] << ' ' << edge[i][k] << '\n';
					exist = 0;
					dfs(i, -1);
					if (exist) {
						found = 1;
						// cout << "par " << edge[i][j] << ' ' << edge[i][k] << '\n';
						break;
					}
				}
			}
		}
		if (found) {
			cout << "YES\n";
			cout << lists.size() << '\n';
			for (int i = 0; i < lists.size(); i++) {
				cout << lists[i].first << ' ' << lists[i].second << '\n';
			}
		} else cout << "NO\n";
	}
	return 0;
}