#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N], lo(N, 0), d(N, 0), par(N, 0);
vector<pair<int, int>> bridge;
int timee = 0;
vector<bool> vis(N, 0), art(N, 0);

void dfs(int u) {
	vis[u] = 1;
	lo[u] = d[u] = timee++;
	for (int i : edge[u]) {
		if (!vis[i]) {
			par[i] = u;
			dfs(i);

			if (lo[i] >= d[u])art[u] = 1;
			if (lo[i] > d[u])bridge.push_back({i, u});
			lo[u] = min(lo[u], lo[i]);
		} else if (i != par[u])lo[u] = min(lo[u], d[i]);
	}
}


int main() {
	FastIO;
	edge[1].push_back(2);
	edge[2].push_back(1);
	edge[2].push_back(3);
	edge[3].push_back(2);
	edge[2].push_back(4);
	edge[4].push_back(2);
	edge[2].push_back(5);
	edge[5].push_back(2);
	edge[2].push_back(6);
	edge[6].push_back(2);
	edge[5].push_back(6);
	edge[6].push_back(5);
	dfs(1);
	// for (int i = 1; i < 7; i++)cout << art[i] << ' ';
	for (int i = 0; i < bridge.size(); i++)cout << bridge[i].first << ' ' << bridge[i].second << '\n';
	return 0;
}