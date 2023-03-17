#include<bits/stdc++.h>
using namespace std;

#define N 405
const int inf = 1e9;
vector<pair<int, int>> edge[N];
vector<int> h(N, 0);
vector<vector<int>> d(N, vector<int> (N, inf));

class PQ {
private:
	pair<int, int> HP[2005];
	int sz = -1;
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return ((2 * i) + 1);
	}
	int right(int i) {
		return ((2 * i) + 2);
	}
	void up(int i) {
		while (i > 0 && HP[parent(i)].first < HP[i].first) {
			swap(HP[parent(i)], HP[i]);
			i = parent(i);
		}
	}
	void down(int i) {
		int maxInd = i;
		int l = left(i);
		if (l <= sz && HP[l].first < HP[maxInd].first)maxInd = l;
		int r = right(i);
		if (r <= sz && HP[r].first < HP[maxInd].first)maxInd = r;
		if (i != maxInd) {
			swap(HP[i], HP[maxInd]);
			down(maxInd);
		}
	}
public:
	void Push(pair<int, int> val) {
		sz = sz + 1;
		HP[sz] = val;
		up(sz);
	}
	void Pop() {
		pair<int, int> ans = HP[0];
		HP[0] = HP[sz];
		sz--;
		down(0);
	}
	bool Empty() {
		return (sz == -1);
	}
	pair<int, int> Top() {
		return HP[0];
	}
};


bool cycle_detect(int n) {
	vector<int> dist(n, inf);
	for (int i = 1; i < n; i++) {
		for (int u = 1; u <= n; u++) {
			for (int j = 0; j < (int) edge[u].size(); j++) {
				pair<int, int> v = edge[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (int j = 0; j < (int)edge[u].size(); j++) {
			pair<int, int> v = edge[u][j];
			if (dist[v.first] > dist[u] + v.second) {
				return 1;
			}
		}
	}
	return 0;
}

void dijkstra(int source) {
	vector<int> dist(N, inf);

	PQ pq;
	pq.Push({0, source});
	dist[source] = 0;
	d[source][source] = 0;

	while (!pq.Empty()) {

		pair<int, int> topp = pq.Top();
		pq.Pop();
		int u = topp.second;

		for (int i = 0; i < (int)edge[u].size(); i++) {
			pair<int, int> v = edge[u][i];
			if (v.second < 0)v.second *= -1;
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				d[source][v.first] = dist[v.first];
				pq.Push({ -dist[v.first], v.first});
			}
		}
	}
}

void bellman(int n, int m) {
	h[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int u = 1; u <= n; u++) {
			for (int j = 0; j < (int) edge[u].size(); j++) {
				pair<int, int> v = edge[u][j];
				h[v.first] = min(h[v.first], h[u] + v.second);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
		mp[u]++;
		mp[v]++;
		if (mp[u] == 1) edge[0].push_back({u, 0});
		if (mp[v] == 1) edge[0].push_back({v, 0});
	}
	if (cycle_detect(n)) {
		bellman(n, m);
		for (int i = 1; i <= n; i++)cout << h[i] << ' ';
		cout << '\n';

		cout << "The graph has negative cycle\n";
		return 0;
	}

	// calculating h for each nodes
	bellman(n, m);

	for (int i = 1; i <= n; i++)cout << h[i] << ' ';
	cout << '\n';

	// calculating new weight for every vertex
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			edge[i][j].second += h[i] - h[edge[i][j].first];
		}
	}

	// running dijkstra from all nodes
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (d[i][j] != inf) d[i][j] += h[j] - h[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] < inf && i != j)cout << i << ' ' << j << ' ' << d[i][j] << '\n';
		}
	}
	return 0;
}