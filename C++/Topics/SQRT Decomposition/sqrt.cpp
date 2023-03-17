#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ":\n";
		int n, q; cin >> n >> q;
		int bs = sqrt(n + .0) + 1;
		vector<int> a(n), b(bs, LLONG_MAX);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i / bs] = min(b[i / bs], a[i]);
		}
		while (q--) {
			int l , r;
			cin >> l >> r;
			l--, r--;
			int ans = LLONG_MAX;
			for (int i = l; i <= r; ) {
				if (i % bs == 0 && r >= i + bs) {
					ans = min(ans, b[i / bs]);
					i += bs;
				} else ans = min(ans, a[i++]);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}