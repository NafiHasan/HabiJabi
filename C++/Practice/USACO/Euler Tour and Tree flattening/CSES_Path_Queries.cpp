#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 200005;
vector<int> edge[N], tour, st(N, 0), subtreesize(N, 1), dis(N, 0), w(N), par(N, 0);
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;
	dis[u] += w[u];
	tour.push_back(u);
	st[u] = tour.size();

	for (int v : edge[u]) {
		if (!vis[v]) {
			dis[v] += dis[u];
			par[v] = u;
			dfs(v);
			subtreesize[u] += subtreesize[v];
		}
	}
}
//Don't forget to clear the global variables
//lo -- hi = range of the index
// i -- j = range of query

long long a[N];
struct info {
	long long prop, sum;
} tree[N * 4];


void init(int node, int lo, int hi) {
	if (lo == hi) {
		tree[node].sum = a[lo];
		return;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo, mid);
	init(right, mid + 1, hi);
	tree[node].sum = tree[left].sum + tree[right].sum;
}

long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL) {
	if (i > hi || j < lo) return 0;
	if (i <= lo && j >= hi)return tree[node].sum + carry * (hi - lo + 1) * 1LL;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;

	return query(left, lo, mid, i , j , carry + tree[node].prop) + query(right, mid + 1, hi, i , j , carry + tree[node].prop);
}

void update(int node, int lo, int hi, int i, int j, long long val) {
	if (i > hi || j < lo) return;
	if (i <= lo && j >= hi) {
		tree[node].sum += 1LL * (hi - lo + 1) * val;
		tree[node].prop += val;
		return;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
}


int32_t main() {
	FastIO;
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> w[i + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	par[1] = 0;
	dfs(1);
	for (int i = 0; i < tour.size(); i++) a[i] = dis[tour[i]];
	init(1, 0, n - 1);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, val;
			cin >> u >> val;
			int cur = query(1, 0, n - 1, st[u] - 1, st[u] - 1) - query(1, 0, n - 1, st[par[u]] - 1, st[par[u]] - 1);  // getting the current distance of path from root. distance[u] - distance[parent[u]] from the updated seg tree
			update(1, 0, n - 1, st[u] - 1, st[u] + subtreesize[u] - 2, val - cur);  // increasing the change in seg tree.
		} else {
			int u;
			cin >> u;
			int ans = query(1, 0, n - 1, st[u] - 1, st[u] - 1);
			cout << ans << '\n';
		}
	}
	return 0;
}