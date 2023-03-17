#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int MOD = 1e9 + 7;

struct mint {
	int v; explicit operator int() const { return v; }
	mint() { v = 0; }
	mint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};

mint& operator+=(mint& a, mint b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mint& operator-=(mint& a, mint b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((long long) a.v * b.v); }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) { assert(a.v != 0); return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)cin >> a[i];

	mint dp[n + 5][m + 5];
	memset(dp, 0, sizeof dp);
	if (a[0] == 0) {
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 1;
		}
	} else dp[0][a[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
		} else {
			int j = a[i];
			dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}
	mint ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += dp[n - 1][i];
	}
	cout << (int)ans << '\n';
	return 0;
}