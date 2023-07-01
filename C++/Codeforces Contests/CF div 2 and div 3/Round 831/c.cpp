#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n ; i++)cin >> a[i];
		sort(a.begin(), a.end());
		// int lo = 1, hi = n - 2, mid, ind = n - 2;
		// while (lo <= hi) {
		// 	mid = (lo + hi) / 2;
		// 	if (a[mid] < a[n - 1]) {
		// 		lo = mid + 1;
		// 		ind = mid;
		// 	} else hi = mid - 1;
		// }
		// int ind2 = 1;
		// lo = 1, hi = n - 2;
		// while (lo <= hi) {
		// 	mid = (lo + hi) / 2;
		// 	if (a[mid] > a[0]) {
		// 		hi = mid - 1;
		// 		ind2 = mid;
		// 	} else lo = mid + 1;
		// }
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans, a[n - 1] - a[i] + a[i + 1] - a[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans, a[i + 1] + a[i + 1] - a[i] - a[0]);
		}
		// long long ans = max(a[ind2] - a[0] + a[n - 1] - a[0], a[n - 1] - a[0] + a[n - 1] - a[ind]);
		cout << ans << '\n';
	}
	return 0;
}