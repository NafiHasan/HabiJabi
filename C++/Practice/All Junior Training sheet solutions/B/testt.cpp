#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 400005;

vector<int>ans, edge[N];
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;
	for (int i : edge[u]) {
		if (!vis[i])dfs(i);
	}
	ans.push_back(u);
}

void toposort(int n) {
	for (int i = 0; i < N; i++)vis[i] = 0;
	ans.clear();
	for (int i = 0; i < N; i++)edge[i].clear();

	for (int i = 0; i < n; i++) {
		if (!vis[i])dfs(i);
	}
	reverse(ans.begin(), ans.end());
}


int main() {
	fast_io();

	return 0;
}