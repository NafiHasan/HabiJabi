#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		int cln = __builtin_clz(n);
		if (__builtin_clz(n) == __builtin_clz(x)) {
			cout << "0\n";
			continue;
		}
		long long ans = 1, mat = 0;
		int last = 0;
		for (int i = 0; (1 << i) <= n; i++) {
			// cout << mat << '\n';
			// if (((1 << i) & n) != 0)mat ^= (1 << i);
			if (((1 << i) & x) == 0) {
				ans *= 2LL;
				// mat ^= ( 1 << i);
			}
		}
		// // cout << ans << '\n';
		// int ans2 = 0;
		// int cntt = 0;
		// // cout << cln << '\n';
		// for (int i = 31; i >= 0; i--) {
		// 	// cout << i << '\n';
		// 	if (((1 << i) & n) != 0 && ((1 << i) & x) == 0) {
		// 		cntt++;
		// 	}
		// }
		// int lef = 31 - cln;
		// if (((1 << lef) & n) != 0 && ((1 << lef) & x) == 0)cntt--;

		// // if (ans2 > 0)ans2--;
		// ans2 = (1 << cntt);
		// ans += ans2;
		// if ((n & x) == 0)ans--;
		// for (int i = 31; i >= 0; i--) {
		// 	if (((1 << i) & n) != 0 && ((1 << i) & x) != 0) {
		// 		ans = 0;
		// 		break;
		// 	}
		// }
		ans -= (ans - n);
		cout << ans << '\n';
	}
	return 0;
}