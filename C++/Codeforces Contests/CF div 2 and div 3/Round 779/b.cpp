#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod = 998244353;
int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		ll fac = 1;
		if (n % 2 == 1) {
			cout << "0\n";
			continue;
		}
		n /= 2;
		for (int i = 2; i <= n; i++) {
			fac *= i;
			fac %= mod;
		}
		fac = fac * fac % mod;
		cout << fac << '\n';
	}
	return 0;
}