const int SZ = 105;
const int MOD = 1e9 + 7;
int mat[SZ][SZ], where[SZ], ans[SZ];
ll bigMod(ll a, ll b, ll m) {
	ll ret = 1LL;
	a %= m;
	while (b) {
		if (b & 1LL) ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1LL;
	}
	return ret;
}
int GaussJordan(int n, int m, int P) {
	SET(where); /// sets to -1
	for (int r = 0, c = 0; c < m && r < n; c++) {
		int mx = r;
		for (int i = r; i < n; i++) if ( mat[i][c] > mat[mx][c] ) mx = i;
		if ( mat[mx][c] == 0 ) continue;
		if (r != mx) for (int j = c; j <= m; j++) swap(mat[r][j], mat[mx][j]);
		where[c] = r;
		int mul, minv = bigMod(mat[r][c], P - 2, P);
		int temp;
		for (int i = 0; i < n; i++) {
			if ( i != r && mat[i][c] != 0) {
				mul = ( mat[i][c] * (long long) minv ) % P;
				for (int j = c; j <= m; j++) {
					temp = mat[i][j];
					temp -= ( ( mul * (long long) mat[r][j] ) % P );
					temp += P;
					if ( temp >= P ) temp -= P;
					mat[i][j] = temp;
				}
			}
		}
		r++;
	}
	for (int j = 0; j < m; j++) {
		if (where[j] != -1) ans[j] = (mat[where[j]][m] * 1LL * bigMod(mat[where[j]][j], P - 2, P) ) % P;
		else ans[j] = 0;
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += ( ans[j] * 1LL * mat[i][j] ) % P;
			if (sum >= P) sum -= P;
		}
		if ( sum != mat[i][m] ) return 0; /// no solution
	}
	int cnt = 0;
	for (int j = 0; j < m; j++) if (where[j] == -1) cnt++;
	return bigMod(P, cnt, MOD);
}