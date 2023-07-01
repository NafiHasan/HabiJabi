#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);

int root;
int cycle = 0;
void dfs(int u, int par) {
	vis[u] = 1;

	for (int v : edge[u]) {
		if (!vis[v]) {
			dfs(v, u);
		} else if (vis[v] && v == root && v != par)cycle++;
	}
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);

		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			edge[i].push_back(a[i]);
			edge[a[i]].push_back(i);
		}
		cycle = 0;
		int comp = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				comp++;
				root = i;
				dfs(i, -1);
			}
		}
		if (cycle < comp)cycle++;
		cout << cycle << ' ' << comp << '\n';
	}
	return 0;
}