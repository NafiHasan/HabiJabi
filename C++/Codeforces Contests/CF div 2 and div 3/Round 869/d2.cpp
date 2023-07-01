// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;

// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber) {

	// already (completely) visited vertex.
	if (color[u] == 2) {
		return;
	}

	// seen vertex, but was not completely visited -> cycle detected.
	// backtrack based on parents to find the complete cycle.
	if (color[u] == 1) {
		vector<int> v;
		cyclenumber++;

		int cur = p;
		v.push_back(cur);

		// backtrack the vertex which are
		// in the current cycle thats found
		while (cur != u) {
			cur = par[cur];
			v.push_back(cur);
		}
		cycles.push_back(v);
		return;
	}
	par[u] = p;

	// partially visited.
	color[u] = 1;

	// simple dfs on graph
	for (int v : graph[u]) {

		// if it has not been visited previously
		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u, color, par, cyclenumber);
	}

	// completely visited.
	color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int& cyclenumber) {

	// print all the vertex with same cycle
	for (int i = 0; i < cyclenumber; i++) {
		// Print the i-th cycle
		cout << "Cycle Number " << i + 1 << ": ";
		for (int x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			graph[i].clear();

		}
		cycles.clear();
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
		}
		int color[n];
		int par[n];

		memset(color, 0, sizeof(color));
		memset(color, 0, sizeof(par));

		// store the numbers of cycle
		int cyclenumber = 0;

		// call DFS to mark the cycles
		dfs_cycle(1, 0, color, par, cyclenumber);

		printCycles(cyclenumber);
		int found = -1;
		vector<pair<int, int>> ans;
		for (int i = 0; i < cycles.size() && found == -1; i++) {
			vector<int> part(n + 5, 0);
			for (int j = 0; j < cycles[i].size(); j++)part[cycles[i][j]]++;
			for (int j = 0; j < cycles[i].size(); j++) {
				if (graph[cycles[i][j]].size() >= 4) {
					found = cycles[i][j];
					break;
				}
			}
			if (found != -1) {
				ans.clear();
				for (int j = 0; j < cycles[i].size(); j++) {
					// cout << j << '\n';
					int v = cycles[i][j];
					int v2 = cycles[i][(j + 1) % (int)cycles[i].size()];
					ans.push_back({v, v2});
					cout << i << ' ' << v << ' ' << v2 << '\n';
					int cnt = 0;
					if (v == found) {
						cout << "found " << v << '\n';
						for (int k = 0; k < graph[v].size() && cnt < 2; k++) {
							int w = graph[v][k];
							cout << w << "par " << '\n';
							if (part[w] == 0) {
								cnt++;
								ans.push_back({v, w});
							}
						}
					}
					if (cnt < 2) {
						found = -1;
						break;
					}
				}
			}

		}
		if (ans.size() > 0) {
			cout << "YES\n";
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].first << ' ' << ans[i].second << '\n';
			}
		} else cout << "NO\n";
	}
}
