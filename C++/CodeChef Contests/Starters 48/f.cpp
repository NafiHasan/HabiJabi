#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int k, now = 0;
const int N = 200005;
string s(N, '0');
vector<int> edge[N], cnt(N, 0);
vector<bool> vis(N, 0);

void dfs(int u) {
	// cout << u << '\n';
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i);
			cnt[u] += cnt[i];
		}
	}
	if (cnt[u] % 2 == 1)now++;
	if (now < k) {
		// if (u == 5)cout << "f";
		if (cnt[u] % 2 == 0) {
			cnt[u]++;
			now++;
			s[u - 1] = '1';
		}
	} else if (now > k) {
		if (cnt[u] % 2 == 1) {
			cnt[u]++;
			now--;
			s[u - 1] = '1';
		}
	}
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n >> k;
		now = 0;
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0;
			cnt[i] = 0;
			s[i] = '0';
		}
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			edge[x].push_back(i);
		}
		dfs(1);
		for (int i = 0; i < n; i++)cout << s[i];
		cout << '\n';
	}
	return 0;
}