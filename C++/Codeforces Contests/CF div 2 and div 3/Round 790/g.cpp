#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 4005;
vector<int> edge[N];
vector<int> col(N);
vector<bool> vis(N, 0);
string s;
int ans = 0;

int dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			col[u] += dfs(i);
		}
	}
	if (s[u - 1] == 'W')col[u]++;
	else col[u]--;
	return col[u];
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ans = 0;
		for (int i = 0; i < N; i++) {
			edge[i].clear();
			vis[i] = 0;
			col[i] = 0;
		}
		int n;
		cin >> n;
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			edge[x].push_back(i);
		}
		cin >> s;
		dfs(1);
		int all = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0)all++;
		}
		cout << all << '\n';
	}
	return 0;
}