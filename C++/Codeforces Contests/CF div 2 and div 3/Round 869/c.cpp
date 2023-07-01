#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<int> baad;
	for (int i = 0; i < n - 2; i++) {
		if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])baad.push_back(i);
	}
	while (q--) {
		int l, r, tl, tr;
		cin >> l >> r;
		tl = l, tr = r;
		l--, r -= 3;
		if (r < l) {
			cout << tr - tl + 1 << '\n';
		} else {
			int lo = 0, hi = baad.size() - 1, mid, st = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (baad[mid] < l) {
					lo = mid + 1;
				} else {
					st = mid;
					hi = mid - 1;
				}
			}
			lo = 0, hi = baad.size() - 1;
			int en = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (baad[mid] > r) {
					hi = mid - 1;
				} else {
					en = mid;
					lo = mid + 1;
				}
			}
			int ans = (tr - tl + 1) - (en - st + 1);
			if (en < st || en == -1 || st == -1)ans = tr - tl + 1;
			cout << ans << '\n';
		}
	}
	return 0;
}