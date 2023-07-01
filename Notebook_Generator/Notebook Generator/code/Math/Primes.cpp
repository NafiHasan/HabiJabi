const int N = 1000000 + 6;
vector<long long>primes;
bitset<N>flag;
vector<long long>v;
void siv() {
	flag[1] = 1;
	for ( int i = 2; i * i <= N; i++ ) {
		if ( flag[i] == 0 ) {
			for ( int j = i * i; j < N; j += i ) flag[j] = 1;
		}
	}
	for ( int i = 2; i < N; i++ ) {
		if ( flag[i] == 0 ) primes.push_back(i);
	}
}
long long mul(long long a, long long b, long long mod) {
	long long res = 0;
	a %= mod;
	while (b) {
		if (b & 1) res = (res + a) % mod;
		a = (2 * a) % mod;
		b >>= 1; // b = b / 2
	}
	return res;
}
long long mod_inverse( long long n, long long p ) {
	long long x, y, g;
	g = gcd_extended( n, p, x, y );
	if ( g < 0 ) x = -x;
	return (x % p + p) % p;
}
long long mpow( long long x, long long y, long long mod ) {
	long long ret = 1;
	while ( y ) {
		if ( y & 1 ) ret = mul(ret, x, mod);
		y >>= 1, x = mul(x, x, mod);
	}
	return ret % mod;
}
int isPrime( long long p ) {
	if ( p < 2 || !(p & 1) ) return 0;
	if ( p == 2 ) return 1;
	long long q = p - 1, a, t;
	int k = 0, b = 0;
	while ( !(q & 1) ) q >>= 1, k++;
	for ( int it = 0; it < 2; it++ ) {
		a = rand() % (p - 4) + 2;
		t = mpow( a, q, p );
		b = (t == 1) || ( t == p - 1 );
		for ( int i = 1; i < k && !b; i++ ) {
			t = mul(t, t, p);
			if ( t == p - 1 ) b = 1;
		}
		if ( b == 0 ) return 0;
	}
	return 1;
}
long long pollard_rho( long long n, long long c ) {
	long long x = 2, y = 2, i = 1, k = 2, d;
	while ( 1 ) {
		x = ( mul(x, x, n) + c );
		if ( x >= n ) x -= n;
		d = gcd(x - y, n);
		if ( d > 1 ) return d;
		if ( ++i == k ) y = x, k <<= 1;
	}
	return n;
}
map<long long, int>mp;
void factorize( long long n ) {
	int l = primes.size();
	for ( int i = 0; primes[i]*primes[i] <= n && i < l; i++ ) {
		if ( n % primes[i] == 0 ) {
			mp[primes[i]] = 1;
			while ( n % primes[i] == 0 ) n /= primes[i];
		}
	}
	if ( n != 1 ) mp[n] = 1;
}
void lfactorize( long long n ) {
	if ( n == 1 ) return;
	if ( n < 1e9 ) {
		factorize(n);
		return;
	}
	if ( isPrime(n) ) {
		mp[n] = 1;
		return;
	}
	long long d = n;
	for ( int i = 2; d == n; i++ ) d = pollard_rho(n, i);
	lfactorize(d);
	lfactorize(n / d);
}
long long f(long long r, vector<long long> v1) {
	int sz = v1.size();
	long long res = 0;
	for (long long i = 1; i < (1 << sz); i++) {
		int ct = 0;
		long long mul = 1;
		for (int j = 0; j < sz; j++ ) {
			if (i & (1 << j)) {
				ct++;
				mul *= v1[j];
			}
		}
		long long sign = -1;
		if (ct & 1)sign = 1;
		res += sign * (r / mul);
	}
	return r - res;
}
