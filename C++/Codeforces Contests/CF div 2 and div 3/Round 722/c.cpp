#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

ll best = 0;
vector<ll>leftval(100005);
vector<ll>rightval(100005);
vector<ll>ed[100005];
vector<bool>vis(100005, 0);
void dfs(int u, ll left, ll right) {
	vis[u] = 1;
	for (int i = 0; i < ed[u].size(); i++) {
		leftval[ed[u][i]] = max(abs(leftval[ed[u][i]] - left), abs(leftval[ed[u][i]] - right));
		rightval[ed[u][i]] = max(abs(rightval[ed[u][i]] - left), abs(rightval[ed[u][i]] - right));
		ll leftbest = max(rightval[ed[u][i]], leftval[ed[u][i]]);
		ll rightbest =
		    best += nbest;
		cout << ed[u][i] << en;
		cout << leftval[ed[u][i]] << " " << rightval[ed[u][i]] << en;
		if (vis[ed[u][i]] == 0)dfs(ed[u][i], leftval[ed[u][i]], rightval[ed[u][i]]);
	}
}
int main() {
	fast_io();
	w(t) {
		int n;
		cin >> n;
		best = 0;
		for (int i = 0; i < n; i++) {
			leftval[i] = 0;
			rightval[i] = 0;
			vis[i] = 0;
			ed[i].clear();
		}
		for (int i = 0; i < n ; i++) {
			cin >> leftval[i] >> rightval[i];
		}
		int start = -1;
		for (int i = 0; i < n - 1; i++) {
			ll u, v;
			cin >> u >> v;
			u--; v--;
			ed[u].push_back(v);
			ed[v].push_back(u);
			if (start == -1 && (int)ed[u].size() == 1) {
				start = u;
			} else if (start == -1 && (int)ed[v].size() == 1)start = v;
		}
		dfs(start, leftval[start], rightval[start]);
		cout << best << en;
	}
	return 0;
}