#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 400005;
vector<int> edge[N], tour, st(N, 0), en(N, 0);
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;
	tour.push_back(u);
	st[u] = tour.size();

	for (int v : edge[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
	tour.push_back(u);
	en[u] = tour.size();
}


long long a[N], tree[N * 4];


void init (int node , int lo, int hi) {
	if (lo == hi) {
		tree[node] = a[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;
	init (left, lo, mid);
	init (right, mid + 1, hi);
	tree[node] = tree[left] + tree[right];
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return query (left, lo, mid, i, j) + query (right, mid + 1, hi, i, j);
}

void update(int node, int lo, int hi, int i, long long new_value) {
	if (i < lo || i > hi) return;
	if (lo == hi) {
		tree[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, new_value);
	update(right, mid + 1, hi, i, new_value);
	tree[node] = tree[left] + tree[right];
}



int32_t main() {
	FastIO;
	int n, q;
	cin >> n >> q;
	vector<int> w(n + 5, 0);
	for (int i = 0; i < n; i++)cin >> w[i + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	for (int i = 0; i < tour.size(); i++) {
		// cout << tour[i] << ' ';
		a[i] = w[tour[i]];
	}
	init(1, 0, 2 * n - 1);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, val;
			cin >> u >> val;
			update(1, 0, 2 * n - 1, st[u] - 1, val);
			update(1, 0, 2 * n - 1, en[u] - 1, val);
		} else {
			int u;
			cin >> u;
			int ans = query(1, 0, 2 * n - 1, st[u] - 1, en[u] - 1);
			ans /= 2;
			cout << ans << '\n';
		}
	}
	return 0;
}