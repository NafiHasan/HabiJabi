#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int lo = 0, hi = m - 1, mid, ind1 , ind2;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (b[mid] == a[i]) {
				ind1 = mid;
				break;
			} else if (b[mid] < a[i]) {
				lo = mid + 1;
				ind1 = mid;
			} else hi = mid - 1;
		}

		lo = 0, hi = m - 1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (b[mid] == a[i]) {
				ind2 = mid;
				break;
			} else if (b[mid] < a[i]) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
				ind2 = mid;
			}
		}
		int cur = min(abs(a[i] - b[ind1]), abs(a[i] - b[ind2]));
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}