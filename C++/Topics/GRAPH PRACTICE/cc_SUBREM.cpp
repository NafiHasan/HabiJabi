#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const int N = 100005;
vector<int> edge[N];
vector<ll> w(N, 0), prof(N, -1e10);
vector<bool> vis(N, 0);
ll x;

void dfs(int u) {
	vis[u] = 1;


	ll add = w[u], sum = 0;
	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i);
			add += prof[i];
			// sum += w[i];
		}
	}
	prof[u] = max(prof[u], -x);
	// cout << u << ' ' << prof[u] << '\n';
	prof[u] = max(prof[u], add);
}



int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> w[i + 1];
			edge[i].clear();
			vis[i] = 0;
			prof[i] = -1e10;
		}
		prof[n] = -1e10;
		edge[n].clear();
		vis[n] = 0;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1);
		cout << prof[1] << '\n';
	}
	return 0;
}