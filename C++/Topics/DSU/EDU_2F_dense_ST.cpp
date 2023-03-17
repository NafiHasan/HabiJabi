#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 2e3 + 10;
vector<int> par(N), rnk(N, 0);

#define int long long
const int inf = 1e18;
void makeset(int n) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

int32_t main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({w, {u, v}});
	}
	sort(edge.begin(), edge.end());
	int mx = 0;
	int ans = inf;
	for (int i = 0; i < edge.size(); i++) {
		int mn = edge[i].first;
		mx = -inf;
		// set<int> st;
		int cnt = 0;
		makeset(n);
		for (int j = i; j < edge.size(); j++) {
			if (cnt == n - 1)break;
			if (get(edge[j].second.first) != get(edge[j].second.second)) {
				mx = max(mx, edge[j].first);
				union_set(edge[j].second.first, edge[j].second.second);
				cnt++;
				// st.insert(edge[j].second.first);
				// st.insert(edge[j].second.second);
			}
		}
		bool ok = 1;
		int root = -1;
		for (int j = 1; j <= n; j++) {
			if (root == -1)root = get(j);
			else if (root != get(j)) {
				ok = 0;
				break;
			}
		}
		if (ok)ans = min(ans, mx - mn);
		else break;
	}
	if (ans == inf)cout << "NO\n";
	else {
		cout << "YES\n" << ans << '\n';
	}
	return 0;
}