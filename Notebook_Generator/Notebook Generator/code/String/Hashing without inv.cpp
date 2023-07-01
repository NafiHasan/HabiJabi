long long h[400005];
long long MOD[400005];
int L;
void pre_hash( string s ) {
	long long p = 31 , m = 1e9 + 9, power = 1, hash = 0;
	int z = 0;
	for ( int i = s.size() - 1; i >= 0; i-- ) {
		hash = ( hash * p + (s[i] - 'A' + 1) ) % m;
		h[i] = hash;
		MOD[z] = power;
		z++;
		power = (power * p) % m;
	}
}
long long f( int l, int r ) {
	long long val = h[r], m = 1e9 + 9;
	if ( l != L - 1 ) {
		long long val2 = (h[l + 1] % m * MOD[l - r + 1] % m ) % m;
		val -= val2;
		val += m;
		val %= m;
	}
	if ( val < 0 ) val = (val + m) % m;
	return val;
}