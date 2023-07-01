#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	double n;
	cin >> n;
	double lo = 0, hi = n, mid, ans = 0;
	int cnt = 0;
	while (lo <= hi) {
		cnt++;
		if (cnt > 100)break;
		mid = (lo + hi) / 2.0;
		// cout << mid << ' ' << mid * mid << '\n';
		if (abs(mid * mid - n) <= 1e-6) {
			ans = mid;
			// cout << ans << 'n';
			break;
		} else if (mid * mid > n) {
			hi = mid - 0.00000000001;
		} else lo = mid + 0.0000000001;
	}
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}