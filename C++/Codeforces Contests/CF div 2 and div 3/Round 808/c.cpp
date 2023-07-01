#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		string s(n, '0');
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// if (a[i] <= q)s[i] = '1';
		}
		int tmp = q, mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (q == 0)break;
			if (a[i] <= q) {
				mx = max(mx, a[i]);
				s[i] = '1';
			}
			if (a[i] > q) {
				if (q >= mx) {
					s[i ] = '1';
					q--;
				}
			}
		}
		// cout << q << '\n';
		// if (a[n - 1] > tmp) {
		// 	s[n - 1] = '1';
		// }
		cout << s << '\n';
	}
	return 0;
}