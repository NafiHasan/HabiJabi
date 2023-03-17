#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
#define N 100005


vector<ll> edge[N], val(N), mod(N);
vector<bool> vis(N, 0), leaf(N, 1);


void dfs(int u) {
	vis[u] = 1;

	for (int x : edge[u]) {
		if (!vis[x]) {
			leaf[u] = 0;
			val[x] = __gcd(val[x], val[u]);
			dfs(x);
		}
	}
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0; leaf[i] = 1;
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			cin >> val[i + 1];
		}
		for (int i = 0; i < n; i++)cin >> mod[i + 1];
		dfs(1);
		vector<ll> lf;
		for (int i = 1; i <= n; i++) {
			if (leaf[i])lf.push_back(i);
		}
		vector<ll> ans;
		for (int i = 0; i < lf.size(); i++) {
			ll p = lf[i];
			ll tmpmax = mod[p] - __gcd(mod[p], val[p]);
			ans.push_back(tmpmax);
		}
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}