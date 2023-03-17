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
		if (__builtin_popcountll(n) == 1) {
			cout << "-1\n";
			continue;
		}
		if (n % 2 == 1) {
			cout << "2\n";
			continue;
		}
		long long has = 1, cnt2 = 1, tmp = n;
		while (tmp % 2 == 0) {
			tmp /= 2;
			cnt2 *= 2;
		}
		if (cnt2 * 2 > tmp) {
			cout << tmp << '\n';
		} else cout << cnt2 * 2 << '\n';
	}
	return 0;
}