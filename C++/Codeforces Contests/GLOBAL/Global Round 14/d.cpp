#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int>left(n + 1, 0), right(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i < l)left[x]++;
			else right[x]++;
		}
		for (int i = 1; i <= n; i++) {
			if (left[i] > 0 && right[i] > 0) {
				int mn = min(left[i], right[i]);
				left[i] -= mn;
				right[i] -= mn;
			}
		}
		int lcnt = 0, rcnt = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			lcnt += left[i];
			rcnt += right[i];
		}
		int dif = min(lcnt, rcnt);
		ans += dif;
		lcnt -= dif;
		rcnt -= dif;
		vector<int>a, b;
		for (int i = 1; i <= n; i++) {
			if (left[i] > 0) {
				a.push_back(left[i]);
			}
			if (right[i] > 0) {
				b.push_back(right[i]);
			}
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		int inda = 0, indb = 0;
		while (lcnt > 0) {
			if (inda < (int)a.size()) {
				int minus = a[inda] / 2;
				ans += min(lcnt / 2, minus);
				lcnt -= 2 * min(lcnt / 2, minus);
			} else break;
			inda++;
		}
		while (rcnt > 0) {
			if (indb < (int)b.size()) {
				int minus = b[indb] / 2;
				// int f=min(rcnt/2, minus;
				ans += min(rcnt / 2, minus);
				rcnt -= 2 * min(rcnt / 2, minus);
			} else break;
			indb++;
		}
		ans += lcnt;
		ans += rcnt;
		cout << ans << en;
	}
	return 0;
}