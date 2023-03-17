#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ":\n";

		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n ; i++)cin >> a[i];
		while (q--) {
			int l, r;
			cin >> l >> r;
			int lo = 0, hi = n - 1, mid, ind1 = n, ind2 = n;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] >= l) {
					ind1 = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			lo = 0, hi = n - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] <= r) {
					ind2 = mid;
					lo = mid + 1;
				} else hi = mid - 1;
			}
			if (ind1 != n)cout << ind2 - ind1 + 1 << "\n";
			else cout << "0\n";
		}
	}
	return 0;
}