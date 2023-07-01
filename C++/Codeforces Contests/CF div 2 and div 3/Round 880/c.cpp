#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		int st = 1;
		for (int i = 1; i < a; i++) {
			st *= 10LL;
		}
		int end = st * 10LL - 1LL;


		int bmin = 1;
		for (int i = 1; i < b; i++) {
			bmin *= 10LL;
		}
		// int bmin = pow(10LL, (b - 1));
		int bmax = (bmin * 10LL) - 1;

		int cmin = 1;
		for (int i = 1; i < c; i++) {
			cmin *= 10LL;
		}
		int cmax = (cmin * 10LL) - 1;



		int A = -1, B, C;

		for (int i = st; i <= end; i++) {
			int needmin = cmin - i;
			needmin = max(needmin, bmin);
			if ((to_string(needmin)).size() != b) {
				continue;
			}

			int needmax = cmax - i;
			needmax = min(needmax, bmax);

			// cout << k << ' ' << i << ' ' << needmin << ' ' << needmax << '\n';

			if (needmax - needmin + 1 < k) {
				k -= (needmax - needmin + 1);
			} else {
				A = i;
				B = needmin + k - 1;
				C = A + B;
				break;
			}
		}
		if (A == -1) {
			cout << "-1\n";
		} else {
			cout << A << " + " << B << " = " << C << '\n';
		}
	}
	return 0;
}
