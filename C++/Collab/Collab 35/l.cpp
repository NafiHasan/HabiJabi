#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long bigmod (long long a, long long n) {
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main() {
	FastIO;
	long long a, b;
	cin >> a >> b;
	long long ans = 1;
	for (long long i = a; i <= b; i++) {

		long long cnt = 0, g = i;
		for (long long j = i + 1; j <= b; j++) {
			if (__gcd(i, j) == 1)cnt++;
		}
		ans += bigmod(2LL, cnt);
	}
	cout << ans << '\n';
	return 0;
}