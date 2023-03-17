#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<double> pos(n), speed(n);
	for (int i = 0; i < n; i++)cin >> pos[i];
	for (int i = 0; i < n; i++)cin >> speed[i];
	double ans = DBL_MAX;
	double lo = 0, hi = 1e10, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		double tim = 0, tim2 = 0, tim1 = 0;
		for (int i = 0; i < n; i++) {
			tim = max(tim, abs(pos[i] - mid) / speed[i]);
		}
		for (int i = 0; i < n; i++) {
			tim1 = max(tim1, abs(pos[i] - (mid + 0.000000001)) / speed[i]);
		}
		for (int i = 0; i < n; i++) {
			tim2 = max(tim2, abs(pos[i] - (mid - 0.000000001)) / speed[i]);
		}

		ans = min(ans, tim);
		if (tim1 < tim) {
			// cout << mid << ' ' << lo << ' ' << hi << ' ' << tim << '\n';
			lo = mid + 0.000000001;
		} else hi = mid - 0.000000001;
	}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}