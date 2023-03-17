#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 2e5 + 10;

vector<int> par(N), rnk(N, 0), siz(N, 1);

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
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

int main() {
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
	makeset();
	long long ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (get(edge[i].second.first) == get(edge[i].second.second))continue;
		else {
			ans += (long long)edge[i].first;
			union_set(edge[i].second.first, edge[i].second.second);
		}
	}
	cout << ans << '\n';
	return 0;
}