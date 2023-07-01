/*** mat is 0 based
* In every test case, clear mat first and then do the changes
* For solving problems on graphs with probability/expectation, make sure the graph
is connected and a single component. If not, then re-number the vertex and solve
for each connected component separately.
* Complexity --> O( min(n,m) * nm ) **/
const int SZ = 105;
const double EPS = 1e-9;
double mat[SZ][SZ], ans[SZ];
int where[SZ];
int GaussJordan(int n, int m) {
	SET(where); /// sets to -1
	for (int r = 0, c = 0; c < m && r < n; c++) {
		int mx = r;
		for (int i = r; i < n; i++) if ( abs(mat[i][c]) > abs(mat[mx][c]) ) mx = i;
		if ( abs(mat[mx][c]) < EPS ) continue;
		if (r != mx) for (int j = c; j <= m; j++) swap(mat[r][j], mat[mx][j]);
		where[c] = r;
		for (int i = 0; i < n; i++) if ( i != r ) {
				double mul = mat[i][c] / mat[r][c];
				for (int j = c; j <= m; j++) mat[i][j] -= mul * mat[r][j];
			}
		r++;
	}
	for (int j = 0; j < m; j++) {
		if (where[j] != -1) ans[j] = mat[where[j]][m] / mat[where[j]][j];
		else ans[j] = 0;
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < m; j++) sum += ans[j] * mat[i][j];
		if ( abs(sum - mat[i][m]) > EPS ) return 0; /// no solution
	}
	for (int j = 0; j < m; j++) if (where[j] == -1) return INF;
	return 1;
}