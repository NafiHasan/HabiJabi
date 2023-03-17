#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 5e4 + 10;
vector<int> par(N), rnk(N, 0);
void makeset(int n) {
	for (int i = 1; i <= n; i++)par[i] = i;
}

int get(int a) {
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
	int n, m, s;
	cin >> n >> m >> s;
	vector<pair<pair<int, pair<int, int>>, int>> edge;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({{w, {u, v}}, i + 1});
	}
	sort(edge.rbegin(), edge.rend());
	makeset(n);
	// int ans = 0;
	vector<pair<int, int>> notTaken;
	for (int i = 0; i < edge.size(); i++) {
		if (get(edge[i].first.second.first) == get(edge[i].first.second.second)) {
			notTaken.push_back({edge[i].first.first, edge[i].second});
			continue;
		} else {
			union_set(edge[i].first.second.first, edge[i].first.second.second);
		}
	}
	sort(notTaken.begin(), notTaken.end());
	int sum = 0;
	vector<int> ans;
	for (int i = 0; i < notTaken.size(); i++) {
		sum += notTaken[i].first;
		if (sum > s)break;
		ans.push_back(notTaken[i].second);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}