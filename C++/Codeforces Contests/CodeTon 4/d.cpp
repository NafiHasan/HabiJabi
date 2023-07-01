#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int q;
		cin >> q;
		int l = -1, r = -1;
		while (q--) {
			int t;
			cin >> t;
			if (t == 1) {
				int a, b, n;
				cin >> a >> b >> n;
				int last = (n - 1) * (a - b);
				int lt = last + b + 1, rt = last + a;
				if (n == 1)lt = last + 1;
				if (l == -1) {
					l = lt , r = rt;
					cout << "1 ";
				} else if (lt > r || rt < l) {
					cout << "0 ";
				} else {
					l = max(l, lt);
					r = min(r, rt);
					cout << "1 ";
				}
				// cout << l << ' ' << r << '\n';
			} else {
				int a, b;
				cin >> a >> b;
				if (l == -1) {
					cout << "-1 ";
					continue;
				}
				int lo = 0, hi = r / (a - b) + 1, mid, need = -1;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					// cout << mid << '\n';
					int tr = mid * (a - b);
					if (tr + a >= r && tr + b < l && tr > 0) {
						need = mid + 1;
						hi = mid - 1;
					} else if (tr + a >= r && tr < l && tr == 0) {
						need = mid + 1;
						hi = mid - 1;
					} else if (tr + a < r)lo = mid + 1;
					else hi = mid - 1;
				}
				cout << need << ' ' ;
			}
		}
		cout << '\n';
	}
	return 0;
}