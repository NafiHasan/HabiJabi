#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, l;
	cin >> n >> l;
	vector<double>points(n);
	for (int i = 0; i < n; i++)cin >> points[i];
	sort(points.begin(), points.end());
	double ans = max(points[0] - 0, l - points[n - 1]);
	for (int i = 1; i < n; i++) {
		ans = max(ans, (points[i] - points[i - 1]) / 2.0);
	}
	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}