long long p = 1e9 + 7;
long long fact[1000005];
int n, m, k;
long long s( long long N, long long R )
{
	if ( N == 0 && R == 0 ) return 1;
	if ( N == 0 || R == 0 ) return 0;
	long long ans = 0;
	for ( int i = 1; i <= R; i++ ) {
		long long par;
		if ( (R - i) % 2 == 0 ) par = 1;
		else par = -1;
		par = (par + p) % p;
		long long temp = (ncr(R, i) * bm(i, N)) % p;
		temp = (temp % p * par % p) % p;
		ans = (ans % p + temp % p) % p;
	}
	return (ans * bm( fact[R], p - 2 )) % p;
}