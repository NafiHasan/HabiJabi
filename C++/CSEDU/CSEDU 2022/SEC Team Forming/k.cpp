#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	map<int, int>mp;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		mp[b[i]]++;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// int ans = INT_MAX, lo = 0, hi = 1000000000, mid;
	// while (lo <= hi) {
	// 	mid = (lo + hi) / 2;
	// 	cout << mid << '\n';
	// 	bool ok = 0;
	// 	for (int i = 0; i < n ; i++) {
	// 		if (mp[a[i] + mid] > 0 || mp[a[i] - mid] > 0) {
	// 			ok = 1;
	// 			cout << a[i] << ' ' << mid << '\n';
	// 			break;
	// 		}
	// 	}
	// 	if (ok) {
	// 		hi = mid - 1;
	// 		ans = min(ans, mid);
	// 	} else lo = mid + 1;
	// }
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		int lo = 0, hi = m - 1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (b[mid] < a[i])lo = mid + 1;
			else {
				ans = min(ans, abs(a[i] - b[mid]));
				hi = mid - 1;
			}
		}
		lo = 0, hi = m - 1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (b[mid] >= a[i])hi = mid - 1;
			else {
				ans = min(ans, abs(a[i] - b[mid]));
				lo = mid + 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}