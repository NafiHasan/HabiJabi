#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n % 7 == 0) {
			cout << n << '\n';
			continue;
			// break;
		}
		n = n / 10;
		n *= 10;
		// cout << n << '\n';
		// break;
		for (int i = n; i < n + 10; i++) {
			if (i % 7 == 0) {
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}