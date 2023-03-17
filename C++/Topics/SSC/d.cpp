#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const long long p = 1e9 + 7;

long long bigmod (long long a, long long n) {
	a %= p;
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans % p;
}


int main() {
	FastIO;
	long long n;
	cin >> n;
	long long ans = bigmod(10LL, n);
	ans %= p;
	ans += bigmod(8LL, n);
	ans %= p;
	ans = (ans - (((2LL * bigmod(9LL, n) % p) + p) % p) + p ) % p;
	if (ans < 0)ans += p;
	ans %= p;
	cout << ans << '\n';
	return 0;
}