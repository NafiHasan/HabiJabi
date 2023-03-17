#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 100005;
int timer = 0;
int Log = 17;
vector<int> tin(N), tout(N);
vector<pair<int, int>> edge[N];
vector<vector<int>> par(N, vector<int> (18, -1)), mn(N, vector<int> (18, INT_MAX)), mx(N, vector<int> (18, INT_MIN));
vector<bool> vis(N, 0);

void dfs(int u) {
	// cout << u << '\n';
	vis[u] = 1;
	tin[u] = timer++;
	for (pair<int, int> v : edge[u]) {
		// cout << v.first << '\n';
		if (!vis[v.first]) {
			dfs(v.first);
			par[v.first][0] = u;
			mn[v.first][0] = v.second;
			mx[v.first][0] = v.second;
		}
	}
	tout[u] = timer++;
}

int isAncestor(int u, int v) {
	if (tin[u] <= tin[v] && tout[u] >= tout[v])return u;
	if (tin[v] <= tin[u] && tout[v] >= tout[u])return v;
	return -1;
}

void preProcess(int n) {
	Log = ceil(log2(n));
	for (int i = 1; i <= Log; i++) {
		for (int j = 0; j < n; j++) {
			if (par[j][i - 1] != -1) {
				int tmp = par[j][i - 1];
				par[j][i] = par[tmp][i - 1];
				mn[j][i] = min(mn[j][i - 1], mn[tmp][i - 1]);
				mx[j][i] = max(mx[j][i - 1], mx[tmp][i - 1]);
			}
		}
	}
}

int kthParent(int parent, int node) {
	// cout << parent << ' ' << node << '\n';
	// if (parent == node)return 0;
	int k = 0;
	int i = Log;
	while (i >= 0 && node != parent) {
		if (isAncestor(par[node][i], parent) == parent) {
			k += (1 << i);
			node = par[node][i];
		}
		i--;
	}
	return k;
}

int calcMin(int node, int k) {
	// if (k == 0)return 0;
	int ans = INT_MAX;
	int i = Log;
	while (k > 0 && i >= 0) {
		if ((1 << i) <= k) {
			k -= (1 << i);
			ans = min(ans, mn[node][i]);
			node = par[node][i];
		}
		i--;
	}
	return ans;
}

int calcMax(int node, int k) {
	// if (k == 0)return 0;
	int ans = INT_MIN;
	int i = Log;
	while (k > 0 && i >= 0) {
		if ((1 << i) <= k) {
			k -= (1 << i);
			ans = max(ans, mx[node][i]);
			node = par[node][i];
		}
		i--;
	}
	return ans;
}

int main() {
	FastIO;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});

	}
	dfs(0);

	preProcess(n);

	int q;
	cin >> q;
	while (q--) {
		int u, v, tmpu, tmpv;
		cin >> u >> v;
		u--, v--;

		tmpu = u, tmpv = v;
		int cur;
		// cout << u << ' ' << v << '\n';
		cur = isAncestor(u, v);
		for (int i = Log; i >= 0 && cur == -1; i--) {
			if (par[v][i] != -1 && isAncestor(u, par[v][i]) == -1) {
				v = par[v][i];
			}
		}
		if (cur == -1)cur = par[v][0];

		int num1 = kthParent(cur, tmpu);
		int num2 = kthParent(cur, tmpv);

		cout << u + 1 << ' ' << tmpv + 1 << ' ' << cur + 1 << '\n';

		int ansMin = min(calcMin(tmpu, num1) , calcMin(tmpv, num2));
		int ansMax = max(calcMax(tmpu, num1), calcMax(tmpv, num2));
		cout << ansMin << ' ' << ansMax << '\n';
	}
	return 0;
}