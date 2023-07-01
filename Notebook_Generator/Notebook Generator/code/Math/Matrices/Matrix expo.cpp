long long a, b, n, m, F[2][2], f[2][2];
long long p = 1e9 + 7;
void multiply( long long a[2][2], long long b[2][2]) {
	long long g[2][2];
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			g[i][j] = 0; for ( int k = 0; k < 2; k++) g[i][j] = ( (g[i][j] % p) + ((a[i][k] % p) * (b[k][j] % p)) % p ) % p;
		}
	}
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) F[i][j] = g[i][j];
	}
}
void power( long long N ) {
	if ( N == 1 ) return;
	if ( N % 2 == 0 ) { power( N / 2 ); multiply(F, F); }
	else {power(N - 1); multiply(F, f);}
	return;
}