#include <bits/stdc++.h>
using namespace std;

const int N = 400010;

int mxc, node = 1;
bool vis[N];
vector <int> g[N];
int n, m, in[N], low[N], ptr, compID[N], to[N], from[N];
map <pair <int, int>, bool> invalid;

void go(int u, int par = -1) {
	in[u] = low[u] = ++ptr;
	for (int v : g[u]) {
		if (in[v]) {
			if (v == par) par = -1;
			else low[u] = min(low[u], in[v]);
		} else {
			go(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > in[u])  invalid[ {u, v}] = invalid[ {v, u}] = true;
		}
	}
}

void dfs(int u, int cc = 1) {
	if (mxc < cc) {
		mxc = cc;
		node = u;
	}

	vis[u] = true;
	for (int v : g[u]) {
		if (invalid[ {u, v}]) continue;
		if (!vis[v]) dfs(v, cc + 1);
	}
}

void last(int u) {
	vis[u] = true;
	// cout << u << '\n';
	for (int v : g[u]) if (!vis[v]) {
			// cout << u << ' ' << v << '\n';
			invalid[ {u, v}] = true;
			last(v);
		} else if (!invalid[ {v, u}] )invalid[ {v, u}] = 1;;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		from[i] = u;
		to[i] = v;
	}

	go(1);

	for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
	invalid.clear();
	memset(vis, false, sizeof(vis));
	last(node);

	cout << mxc << "\n";
	for (int i = 0; i < m; ++i) {
		if (invalid[ {from[i], to[i]}]) cout << to[i] << " " << from[i] << "\n";
		else                           cout << from[i] << " " << to[i] << "\n";
	}

	return 0;
}
