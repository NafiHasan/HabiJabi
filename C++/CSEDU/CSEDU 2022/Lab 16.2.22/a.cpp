#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	while (q--) {
		long long x;
		cin >> x;
		int lo = 0, hi = n - 1, mid, ind1 = -1, ind2 = -1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (a[mid] > x)hi = mid - 1;
			else if (a[mid] < x) lo = mid + 1;
			else {
				ind1 = mid;
				hi = mid - 1;
			}
		}
		lo = 0, hi = n - 1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (a[mid] > x)hi = mid - 1;
			else if (a[mid] < x) lo = mid + 1;
			else {
				ind2 = mid;
				lo = mid + 1;
			}
		}
		if (ind1 == -1 || ind2 == -1)cout << "0\n";
		else cout << ind2 - ind1 + 1 << "\n";
	}
	return 0;
}