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
		map<int, int> m;
		int lim = 0, d = 1;
		while ((1 << d) < n) {
			lim = (1 << d);
			d++;
		}
		for (int i = n - 1; i >= lim; i--) {
			cout << i << ' ';
			m[i]++;
		}
		// cout << lim << ' ';
		// int mx = 0;
		for (int i = 0; i < n; i++) {
			// if (i != lim)cout << i << ' ';
			if (m[i] == 0)cout << i << ' ';
			// if (i && i != lim)mx = max(mx, (i ^ (i - 1)));
		}
		// cout << mx << '\n';
		cout << '\n';
	}
	return 0;
}