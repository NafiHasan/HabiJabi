#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const long long mod = 1e9 + 7;
// for (a^n) % mod
long long bigmod (long long a, long long n) {
	a %= mod;
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
int main() {
	FastIO;
	cout << (5 * bigmod(24, mod - 2)) % mod << '\n';
	return 0;
}