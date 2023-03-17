#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int W, H, a, b , c, d, w, h;
		cin >> W >> H >> a >> b >> c >> d >> w >> h;
		if (((w + (c - a)) > W) && ((h + (d - b)) > H)) {
			cout << "-1\n";
			continue;
		}
		if (w <= a || (c + w) <= W || h <= b || (h + d) <= H) {
			cout << "0.0000000\n";
			continue;
		}
		double ans = 99999999999.0;

		//down left
		if (a < w && h > b) {
			if ((w + (c - a)) <= W)  ans = min(ans, (double)abs(w - a));
			if (h + (d - b) <= H) ans = min(ans, (double)abs(h - b));
		}
		//down right
		int x = W - w, y = h;
		if (x < c && y > b) {
			if ((w + (c - a)) <= W)
				ans = min(ans, (double)abs(x - c));
			if (h + (d - b) <= H)
				ans = min(ans, (double)abs(y - b));
		}
		//up left
		y = H - h, x = w;
		if (a < x && d > y) {
			if ((w + (c - a)) <= W) {
				ans = min(ans, (double)abs(x - a));
			}  if (h + (d - b) <= H) {
				ans = min(ans, (double)abs(d - y));
			}
		}
		// up right
		x = W - w;
		if (x < c && d > y) {
			if ((w + (c - a)) <= W) {
				ans = min(ans, (double)abs(x - c));
			}  if (h + (d - b) <= H) {
				ans = min(ans, (double)abs(d - y));
			}
		}
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}