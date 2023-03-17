#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		double R, n;
		cin >> R >> n;
		double pi = 2.0 * acos(0.0);
		double s = sin(pi / n);
		cout << "Case " << cs << ": ";
		cout << fixed << setprecision(10) << R * s / (1.0 + s) << "\n";
	}
	return 0;
}