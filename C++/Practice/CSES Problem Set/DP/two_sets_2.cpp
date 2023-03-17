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

mint dp[250005];
int n;
int a[505];
mint total;

int main() {
	FastIO;
	cin >> n;
	if (n < 3) {
		cout << 0 << '\n';
		return 0;
	}
	total = n * (n + 1);
	if ((int)total % 4 != 0) {
		cout << "0\n";
		return 0;
	}
	total = total / (mint)4;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++)a[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = (int)total; j >= a[i]; j--) {
			if ((int)dp[j - a[i]] != 0)dp[j] += dp[j - a[i]];
		}
	}
	mint ans = dp[(int)total];
	ans = ans / 2;
	cout << (int)ans << '\n';
	return 0;
}