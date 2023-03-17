#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int inf = -1e9 - 10;
const int N = 200005;
vector<pair<int, pair<int, int>> > edge[N];
vector<bool> vis(N, 0);
bool ans = 1;


void dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}


int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		edge[i].push
	}
	return 0;
}