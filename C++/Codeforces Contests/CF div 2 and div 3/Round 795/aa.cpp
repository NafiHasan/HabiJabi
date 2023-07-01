#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		if (n == 1) {
			cout << "3\n";
		} else if (__builtin_popcount(n) == 1) {
			cout << n + 1 << '\n';
		} else {
			long long ans = 0;
			for (long long i = 0; ; i++) {
				if ((( 1LL << i) & n) != 0) {
					ans = (1LL << i);
					break;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}