#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int unsigned long long


const int N = 200005;
vector<int> edge[N], sum(N, 0), c(N, 0), cnt(N, 0);
int n, k;

void dfs(int u) {
	for (int i : edge[u]) {
		dfs(i);
		sum[u] += sum[i];
	}
}

void dfs2(int u) {
	int div = edge[u].size();
	if (div == 0)return;
	vector<pair<int, int>> all;
	for (int i : edge[u]) {
		all.push_back({sum[i], i});
	}
	sort(all.rbegin(), all.rend());
	int got = cnt[u];
	int have = got / div;
	int rem = got % div;
	for (int i = 0 ; i < all.size(); i++) {
		cnt[all[i].second] += have;
		if (rem > 0) {
			cnt[all[i].second]++;
			rem--;
		}
	}
	for (int i : edge[u]) {
		dfs2(i);
	}
}




signed main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			sum[i] = 0;
			cnt[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			int v;
			cin >> v;
			edge[v].push_back(i + 2);
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i + 1];
			sum[i + 1] = c[i + 1];
		}
		cnt[1] = k;
		dfs(1);
		dfs2(1);
		// for (int i = 1; i <= n; i++)cout << cnt[i] << ' ';
		// cout << '\n';
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += cnt[i] * c[i];
		}
		cout << ans << '\n';
	}
	return 0;
}