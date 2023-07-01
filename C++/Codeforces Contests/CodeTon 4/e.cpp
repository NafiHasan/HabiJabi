#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 2e5 + 5;
vector<int> a(N), zero, got(N, 0), adj[N], rep(N);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > edge[N];
vector<bool> vis(N, 0), reach(N, 0), vis2(N, 0);

void dfs(int u, int pre) {
	cout << u << ' ' << pre << ' ' << got[u] << '\n';
	vis[u] = 1;

	while (!edge[u].empty()) {
		pair<int, int> tp = edge[u].top();
		edge[u].pop();
		while (rep[tp.second] != tp.second)tp.second = rep[tp.second];
		// if (u == 2)cout << tp.first << ' ' << tp.second << '\n';
		if (!vis[tp.second]) {
			if (tp.first > got[u]) {
				// cout << tp.second << '\n';
				edge[u].push(tp);
				return;
			}
			got[tp.second] = got[u] + 1;
			while (!edge[u].empty()) {
				pair<int, int> tp2 = edge[u].top();
				edge[u].pop();
				tp2.second = rep[tp2.second];
				if (tp2.second != tp.second && tp2.second != u && tp2.second != pre)edge[tp.second].push(tp2);
			}
			rep[u] = tp.second;
			dfs(tp.second, u);
		} else {
			if (reach[tp.second] && edge[tp.second].size() > 0) {
				got[u] += got[tp.second];
				while (!edge[tp.second].empty()) {

					pair<int, int> top = edge[tp.second].top();
					// cout << tp.second << ' ' <<  top.second << '\n';
					while (top.second != rep[top.second])top.second = rep[top.second];
					if (top.second != u)edge[u].push(top);
					edge[tp.second].pop();
				}
				continue;
			}
		}
	}
}

void dfs2(int u) {
	vis2[u] = 1;
	for (int v : adj[u]) {
		if (!vis2[v])dfs2(v);
	}
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		zero.clear();
		for (int i = 0; i <= n; i++) {
			while (!edge[i].empty())edge[i].pop();
			vis[i] = 0;
			reach[i] = 0;
			got[i] = 0;
			adj[i].clear();
			vis2[i] = 0;
			rep[i] = i;
		}


		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 0)zero.push_back(i);
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push({a[v], v});
			edge[v].push({a[u], u});
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int last = -1;
		for (int i = 0; i < zero.size(); i++) {
			if (!vis[zero[i]]) {
				got[zero[i]]++;
				dfs(zero[i], -1);
				last = zero[i];
				int tmp = zero[i];
				while (tmp != rep[tmp]) {
					reach[tmp] = 1;
					tmp = rep[tmp];
				}
				// reach[zero[i]] = 1;
			}
		}
		bool ans = 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis2[i]) {
				dfs2(i);
				cnt++;
			}
		}
		if (cnt > 1)ans = 0;
		for (int i = 1; i <= n; i++) {
			cout << edge[i].size() << '\n';
			if ((int)edge[i].size() != 0)ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}