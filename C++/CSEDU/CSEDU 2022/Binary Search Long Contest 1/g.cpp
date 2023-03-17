#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";

		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				int dif = a[j] - a[i];
				int sum = a[i] + a[j];
				int lo = j + 1, hi = n - 1, mid, ind1 = n;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (a[mid] > dif && a[mid] < sum) {
						hi = mid - 1;
						ind1 = mid;
					} else if (a[mid] <= dif)lo = mid + 1;
					else  hi = mid - 1;
				}
				lo = ind1 + 1, hi = n - 1;
				int ind2 = ind1;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (a[mid] > dif && a[mid] < sum) {
						lo = mid + 1;
						ind2 = mid;
					} else if (a[mid] <= dif)lo = mid + 1;
					else  hi = mid - 1;
				}
				if (ind1 < n && ind2 < n)ans += ind2 - ind1 + 1;
				// cout << a[i] << ' ' << a[j] << ' ' << ind1 << ' ' << ind2 << '\n';
			}
		}
		cout << ans << "\n";
	}
	return 0;
}