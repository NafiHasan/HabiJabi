#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define N 50005

vector<ll> edge[N];
bool vis[N];
ll ans = 0;
map<pair<ll, ll>, ll> mp;
ll k;
ll root = 1;
void dfs(int u, int dis) {
	vis[u] = 1;

	if (dis == k) {
		if (mp[ {root, u}] == 0) {
			ans++;
			mp[ {root, u}]++;
			mp[ {u, root}]++;
		}
		return;
	}
	for (int x : edge[u]) {
		if (!vis[x])dfs(x, dis + 1);
	}
}

int main() {
	FastIO;
	ll n;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		root = i;
		dfs(i, 0);
	}
	cout << ans << "\n";
	return 0;
}