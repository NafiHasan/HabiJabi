#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 100005;
priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > edge[N];
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;

	vector<pair<int, int>> tmp;
	while (!edge[u].empty()) {
		tmp.push_back(edge[u].top());
		edge[u].pop();
		if (!vis[tmp.back().second]) {
			dfs(tmp.back().second);
		}
		tmp.back().first = max(tmp.back().first(), )
	}
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n;
		cin >> n;
		vector<pair<int, int>> vp(n);

		for (int i = 0; i < n; i++) cin >> vp[i].first ;
		for (int i = 0; i < n; i++) cin >> vp[i].second ;
		for (int i = 0; i < n; i++) {
			if (vp[i].second != 0) {
				edge[vp[i].second].push(vp[i]);
			}
		}

		dfs(1);
	}
	return 0;
}