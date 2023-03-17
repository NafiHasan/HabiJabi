#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const double pi = 3.14159265;

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int r, a , b;
		cin >> r >> a >> b;
		double ans = pi * (double)r * (double)r;
		int cnt = 0;
		while (1) {
			if (cnt % 2 == 0)r *= a;
			else r /= b;
			if (r == 0)break;
			ans += pi * (double)r * (double)r;
			cnt++;
		}
		cout << "Case #" << cs << ": " ;
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}