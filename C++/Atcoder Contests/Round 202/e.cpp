#include <bits/stdc++.h>
using namespace std;


#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N], dis(N, 0), st(N, -1), en(N, -1), disedge[N], preorder;


void dfs(int u) {
	preorder.push_back(u);
	st[u] = preorder.size();

	for (int v : edge[u]) {
		dis[v] = dis[u] + 1;
		dfs(v);
	}
	preorder.push_back(u);
	en[u] = preorder.size();
}


int main() {
	FastIO;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		edge[x].push_back(i);
	}

	dfs(1);

	for (int i = 0; i < preorder.size(); i++) {
		disedge[dis[preorder[i]]].push_back(i + 1);
	}

	int q;
	cin >> q;
	while (q--) {
		int u, d;
		cin >> u >> d;
		int l = st[u], r = en[u];

		int lo = 0, hi = disedge[d].size() - 1, mid;
		int ll = disedge[d].size() - 1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;

			if (disedge[d][mid] < l) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
				ll = min(ll, mid);
			}
		}


		lo = 0, hi = disedge[d].size() - 1;
		int rr = 0;

		while (lo <= hi) {
			mid = (lo + hi) / 2;

			if (disedge[d][mid] > r) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
				rr = max(rr, mid);
			}
		}

		int ans = 0;

		if (disedge[d].size() > 0 && disedge[d][ll] >= l && disedge[d][rr] <= r) {
			ans = rr - ll + 1;
			ans /= 2;
		}
		cout << ans << '\n';
	}

	return 0;
}



