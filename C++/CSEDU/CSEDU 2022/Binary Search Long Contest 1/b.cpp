#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";

		double ab, ac, bc, rat;
		cin >> ab >> ac >> bc >> rat;
		double s = (ab + ac + bc) / 2;
		double area = sqrt(s * (s - ab) * (s - bc) * (s - ac));
		double h = 2 * area / bc;
		double lo = 0, hi = ab, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2.0;
			double ratio = mid / (ab - mid);

		}
	}
	return 0;
}