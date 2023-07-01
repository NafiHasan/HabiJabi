#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 200005;
vector<pair<int,pair<int, int>>> edge[N];
vector<bool> vis(N, 0);
vector<int> ans(N, 0), w(N, 0);
vector<int> tmp;

void dfs(int u, int cost) {
	// cout << u << ' ' << cost << '\n';
	vis[u] = 1;
	if(tmp.size() == 0)tmp.push_back(cost);
	else tmp.push_back(cost + tmp.back());

	int lo = 0, hi = tmp.size() - 1, mid;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if(tmp[mid] <= w[u]){
			lo = mid + 1;
			ans[u] = mid;
		}
		else hi = mid - 1;
	}

	for (auto v : edge[u]){
		if(!vis[v.first]){
			w[v.first] = w[u] + v.second.first;
			dfs(v.first, v.second.second);
		}
	}
	if(tmp.size() > 0)tmp.pop_back();
}



signed main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		for (int i=0; i<=n; i++){
			vis[i] = 0;
			edge[i].clear();
			ans[i] = 0;
			w[i] = 0;
		}
		tmp.clear();

		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			cin >> u >>  v >> w;
			edge[u].push_back({i + 2, {v, w}});
		}
		dfs(1, 0);
		for (int i=2; i<=n; i++)cout << ans[i] << ' ' ;
		cout << '\n';
	}
	return 0;
}