#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int fa = a, fb = b;
		int last = -1, last2 = -1;
		int ans = 1;
		// cout << (3 << ) << '\n';
		int n = 0;
		int fir = -1;
		for (int i = 0; i < 25; i++) {
			if ((a & (1 << i)) != 0 && (b & (1 << i)) == 0)last = i;
			if ((a & (1 << i)) == 0 && (b & (1 << i)) != 0 && last2 <= last)last2 = i;
			if ((a & (1 << i)) != 0)n = i;
			if ((b & (1 << i)) != 0)n = i;
			if (fir == -1 && (b & (1 << i)) != 0)fir = i;

		}
		if (last == -1 && last2 == -1) {
			cout << "1\n";
			continue;
		}
		// cout << last << ' ' << last2 << '\n';
		int tmp = (1 << last2);
		for (int i = last + 1; i < 25; i++) {
			if ((a & (1 << i)) != 0) a = a ^ (1 << i);
			if ((b & (1 << i)) != 0) b = b ^ (1 << i);
		}
		ans += abs(a - b);
		// cout << a << ' ' << b << '\n';
		int tmp2 = fa;
		for (int i = last2 + 1; i < 25; i++) {
			if ((tmp2 & (1 << i)) != 0) tmp2 = tmp2 ^ (1 << i);
		}
		int ans2 = tmp - tmp2;
		for (int i = 0; i < 25; i++) {
			if (i > last2 && (fb & (1 << i)) != 0 && (fa & (1 << i )) == 0) {
				ans2++;
				// cout << last2 << ' ' << i << '\n';
				break;
			} else if (i < last2 && ((fb & (1 << i)) != 0)) {
				ans2++;
				// cout << last2 << ' ' << i << '\n';
				break;
			}
		}
		// cout << fir << ' ';
		// cout << tmp << ' ' << a << '\n';
		ans = min(ans, ans2);
		// cout << ans2 << '\n';
		cout << ans << '\n';
	}
	return 0;
}