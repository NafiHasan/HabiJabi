/*use this to calculate nCr modulo mod, when mod is smaller than n and m. define MOD
Complexity : O(mod + log mod n) */
ll fact[MOD];
ll bigmod(int x, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * x % MOD;
		x = x * x % MOD;
		p >>= 1;
	}
	return res;
}
ll modinv(ll x) {
	return bigmod(x, MOD - 2);
}
void precalc() { //run this
	fact[0] = 1;
	for (int i = 1; i < MOD; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
}
int C(int n, int m) {
	if (m > n) return 0;
	if (m == 0 or m == n) return 1;
	ll ret = fact[n] * modinv(fact[m]) % MOD;
	return ret * modinv(fact[n - m]) % MOD;
}
int nCr(int n, int m) {
	if (m > n) return 0;
	if (m == 0) return 1;
	return nCr(n / MOD, m / MOD) * C(n % MOD, m % MOD) % MOD;
}