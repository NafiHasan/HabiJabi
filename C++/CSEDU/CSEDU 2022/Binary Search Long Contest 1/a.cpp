#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";

		long long q;
		cin >> q;
		long long lo = 0, hi = 1e18, mid, ans = -1;
		while (lo <= hi) {
			long long ad = 0;
			mid = (lo + hi) / 2;
			long long st = 5, tmp = mid;
			while (st <= mid) {
				ad += mid / st;
				st *= 5;
			}
			if (ad == q) {
				ans = mid;
				hi = mid - 1;
			} else if (ad < q) {
				lo = mid + 1;
			} else hi = mid - 1;
		}
		if (ans == -1)cout << "impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}