/*returns maximum/minimum weighted bipartite
,→ matching. Complexity : O(N^2 * M)
flag = -1 minimizes, flag = 1 maximizes. */
#define CLR(a) memset(a, 0, sizeof a)
ll weight[N][M];
int used[M], P[M], way[M], match[M];
ll U[M], V[M], minv[M], ara[N][M];
ll hungarian(int n, int m, int flag) {
	CLR(U), CLR(V), CLR(P), CLR(ara), CLR(way);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ara[i][j] = -flag * weight[i][j];
		}
	}
	if (n > m) m = n;
	int a, b, d;
	ll r, w;
	for (int i = 1; i <= n; i++) {
		P[0] = i, b = 0;
		for (int j = 0; j <= m; j++) minv[j] = INF, used[j] = false;
		do {
			used[b] = true;
			a = P[b], d = 0, w = INF;
			for (int j = 1; j <= m; j++) {
				if (!used[j]) {
					r = ara[a][j] - U[a] - V[j];
					if (r < minv[j]) minv[j] = r, way[j] = b;
					if (minv[j] < w) w = minv[j], d = j;
				}
			}
			for (int j = 0; j <= m; j++) {
				if (used[j]) U[P[j]] += w, V[j] -= w;
				else minv[j] -= w;
			}
			b = d;
		} while (P[b] != 0);
		do {
			d = way[b];
			P[b] = P[d], b = d;
		} while (b != 0);
	}
	for (int j = 1; j <= m; j++) match[P[j]] = j;
	return flag * V[0];
}