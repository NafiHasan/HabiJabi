#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";

		double x, y, c;
		cin >> x >> y >> c;
		double lo = 0, hi = min(x, y), mid, ans = 0;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			double th1 = acos(mid / x);
			double th2 = acos(mid / y);
			double p = c / tan(th1);
			double q = c / tan(th2);
			// cout << th1 << ' ' << th2 << ' ' << p << ' ' << q << " " << mid << '\n';
			if (abs(p + q - mid) <= 1e-9) {
				ans = mid;
				break;
			} else if (p + q < mid) {
				lo = mid + 0.00000000001;
			} else hi = mid - 0.00000000001;
		}
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}