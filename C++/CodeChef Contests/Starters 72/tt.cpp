#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);
int cnt = 0;
void dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			cnt++;
			dfs(i);
		}
	}
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			edge[i + 1].push_back(a[i]);
			edge[a[i]].push_back(i + 1);
		}
		int ans = 0, com = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				cnt = 0;
				dfs(i);
				if (cnt > 0)com++;
				ans += cnt;
			}
		}
		if (ans == 0) {
			cout << "1\n";
			continue;
		}
		if (com == 1)ans--;
		else ans++;
		cout << ans << '\n';
	}
	return 0;
}