#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main() {
	fast_io();
	while (1) {
		ll n, p;
		cin >> n >> p;
		if (n == 0 && p == 0)break;
		ll now = n * n, inc = 8, sq = n;
		if (p == 1) {
			cout << "Line = " << (n + 1) / 2 << ", column = " << (n + 1) / 2 << ".\n";
			continue;
		}
		ll r = n + 1, c = n + 1;
		for (ll i = n; i >= 1; i -= 2) {
			if (i * i >= p) {
				sq = i - 1;
				r--, c--;
				now = i * i;
			}
		}

		// cout << sq << '\n';
		// sq--;
		// cout << r << " " << c << '\n';
		// cout << r << ' ' << c << ' ' << now << ' ' << sq << '\n';
		bool ri = 0, le = 0, dow = 1, up = 0;
		while (now - sq >= p) {
			// cout << now << '\n';
			now -= (sq);
			// if (now == 3)cout << r << ' ' << c << '\n';
			if (dow) {
				dow = 0, le = 1;
				r -= sq;
			} else if (le) {
				le = 0, up = 1;
				c -= sq;
			} else if (up) {
				up = 0, ri = 1;
				r += sq;
			}
		}
		// cout << r << ' ' << c << '\n';
		ll gap = abs(now - p);
		if (dow)r -= gap;
		else if (le) c -= gap;
		else if (up) r += gap;
		else c += gap;
		cout << "Line = " << r << ", column = " << c << ".\n";
	}
	return 0;
}