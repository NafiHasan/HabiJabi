/// O( N * 2^N )
///memory optimized version
for (int i = 0; i < (1 << N); ++i) F[i] = A[i];
for (int i = 0; i < N; ++i) for (int mask = 0; mask < (1 << N); ++mask)
		if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
/// How many pairs in ara[] such that (ara[i] & ara[j]) = 0
/// N --> Max number of bits of any array element
const int N = 20;
int inv = (1 << N) - 1;
int F[(1 << N) + 10];
int ara[MAX];
/// ara is 0 based
long long howManyZeroPairs(int n, int ara[]) {
	CLR(F);
	for (int i = 0; i < n; i++) F[ara[i]]++;
	for (int i = 0; i < N; ++i) for (int mask = 0; mask < (1 << N); ++mask) {
			if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
		}
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += F[ara[i] ^ inv];
	return ans;
}
/// F[mask] = sum of A[i] given that (i&mask)=mask
for (int i = 0; i < (1 << N); ++i) F[i] = A[i];
for (int i = 0; i < N; ++i)
	for (int mask = (1 << N) - 1; mask >= 0; --mask) {
		if (!(mask & (1 << i))) F[mask] += F[mask | (1 << i)];
	}
/// Number of subsequences of ara[0:n-1] such that
/// sub[0] & sub[2] & ... & sub[k-1] = 0
const int N = 20;
int inv = (1 << N) - 1;
int F[(1 << N) + 10];
int ara[MAX];
int p2[MAX]; /// p2[i] = 2^i
///0 based array
int howManyZeroSubSequences(int n, int ara[]) {
	CLR(F);
	for (int i = 0; i < n; i++) F[ara[i]]++;
	for (int i = 0; i < N; ++i)
		for (int mask = (1 << N) - 1; mask >= 0; --mask) {
			if (!(mask & (1 << i)))
				F[mask] += F[mask | (1 << i)];
		}
	int ans = 0;
	for (int mask = 0; mask < (1 << N); mask++) {
		if (__builtin_popcount(mask) & 1) ans = sub(ans, p2[F[mask]]);
		else ans = add(ans, p2[F[mask]]);
	}
	return ans;
}
/// Number of subsequences of ara[0:n-1] such that
/// sub[0] | sub[2] | ... | sub[k-1] = Q
int F[(1 << 20) + 10], ara[MAX];
int p2[MAX]; /// p2[i] = 2^i
/// ara is 0 based
int howManySubsequences(int n, int ara[], int m, int Q) {
	CLR(F);
	for (int i = 0; i < n; i++) F[ara[i]]++;
	if (Q == 0) return sub(p2[F[0]], 1);
	for (int i = 0; i < m; ++i)
		for (int mask = 0; mask < (1 << m); ++mask) {
			if (mask & (1 << i))
				F[mask] += F[mask ^ (1 << i)];
		}
	int ans = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		if (mask & Q != mask) continue;
		if (__builtin_popcount(mask ^ Q) & 1) ans = sub(ans, p2[F[mask]]);
		else ans = add(ans, p2[F[mask]]);
	}
	return ans;
}