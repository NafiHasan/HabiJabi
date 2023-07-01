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
		if (n <= 2 || n % 2 == 1) {
			cout << "-1\n";
			continue;
		}
		long long mn = LLONG_MAX, mx = 0;
		if (n % 4 == 0)mx = n / 4;
		if (n % 6 == 0)mn = n / 6;
		// if (n % 6 == 2) {
		mn = min(mn, n / 6LL + 1);
		mx = max(mx, n / 4);
		// mx = max(mx, n / )
		// }
		// if (n % 6 == 4) {
		mn = min(mn, n / 6 + 1);
		mx = max(mx, n / 4 );
		// }
		cout << mn <<  ' ' << mx << '\n';
	}
	return 0;
}