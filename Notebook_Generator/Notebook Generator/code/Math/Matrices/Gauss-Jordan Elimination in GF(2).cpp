const int SZ = 105;
const int MOD = 1e9 + 7;
bitset <SZ> mat[SZ];
int where[SZ];
bitset <SZ> ans;
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
/// n for row, m for column, modulo 2
int GaussJordan(int n, int m) {
	SET(where); /// sets to -1
	for (int r = 0, c = 0; c < m && r < n; c++) {
		for (int i = r; i < n; i++)
			if ( mat[i][c] ) {
				swap(mat[i], mat[r]); break;
			}
		if ( !mat[r][c] ) continue;
		where[c] = r;
		for (int i = 0; i < n; ++i) if (i != r && mat[i][c]) mat[i] ^= mat[r];
		r++;
	}
	for (int j = 0; j < m; j++) {
		if (where[j] != -1) ans[j] = mat[where[j]][m] / mat[where[j]][j];
		else ans[j] = 0;
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) sum ^= (ans[j] & mat[i][j]);
		if ( sum != mat[i][m] ) return 0; /// no solution
	}
	int cnt = 0;
	for (int j = 0; j < m; j++) if (where[j] == -1) cnt++;
	return bigMod(2, cnt, MOD); /// how many solutions modulo some other MOD
}