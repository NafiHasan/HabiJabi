#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 300005;
vector<int> edge[N];
vector<int> dfsTime(N), low(N);
vector<bool> vis(N, 0), isCut(N, 0);
int timer, arti;

void dfs(int u, int par) {
	vis[u] = 1;
	dfsTime[u] = low[u] = ++timer;
	int child = 0;
	for (int v : edge[u]) {
		if (v == par)
			continue; // don't visit the parent node
		if (vis[v]) {  // cross edge
			low[u] = min(low[u], dfsTime[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfsTime[u] && par != -1) {  // checking among the back edges
				// u is a articulation point
				isCut[u] = 1;
			}
			child++;
		}
	}
	if (par == -1 && child > 1)isCut[u] = 1; // child = how many components will produce if u is removed
}

void find_cutpoints(int n) {
	timer = 0;
	vis.assign(n + 1, 0);
	low.assign(n + 1, -1);
	dfsTime.assign(n + 1, -1);
	isCut.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i, -1);
	}

	for (int i = 1; i <= n; i++) {
		if (isCut[i]) {
			arti++;
			cout << i << '\n';
		}
	}
}



int main() {

	return 0;
}