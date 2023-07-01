// Builds a centroid tree of height O(logn) in O(nlogn).
const int M = 2e5 + 3;
int sz[M], done[M], cpar[M], root;
vector<int>ctree[M];
void go(int u, int p = -1) {
	sz[u] = 1;
	for (int v : g[u]) {
		if (v == p or done[v]) continue;
		go(v, u);
		sz[u] += sz[v];
	}
}
int find_centroid(int v, int p, int n) {
	for (int x : g[v]) {
		if (x != p and !done[x] and sz[x] > n / 2) return find_centroid(x, v, n);
	}
	return v;
}
void decompose(int v = 0, int p = -1) {
	go(v);
	int c = find_centroid(v, -1, sz[v]);
	if (p == -1) root = c;
	done[c] = 1;
	cpar[c] = p;
	if (p != -1) ctree[p].push_back(c);
	for (int x : g[c]) {
		if (!done[x]) decompose(x, c);
	}
}