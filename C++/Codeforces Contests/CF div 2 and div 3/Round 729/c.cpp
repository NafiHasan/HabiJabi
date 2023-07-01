#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

const long long mod = 1000000007;

long long lcm(long long a, long long b) {
	return a * b / __gcd(a, b);
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, rem ;
		cin >> n;
		rem = n;
		long long ans = 0, current = n, fact = 1;
		for (long long i = 2; i < 42LL; i++) {
			fact = lcm(fact, i);
			rem = current - (n / fact);
			ans += ((rem % mod) * i) ;
			current = n / fact;
			ans %= mod;
		}
		cout << ans % mod << "\n";
	}
	return 0;
}