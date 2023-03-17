#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int m, n;
		cin >> m >> n;
		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) ans += (m + 1) / 2;
			else ans += m / 2;
		}
		if (m == 1 || n == 1) {
			ans = m * n;
		} else if (m < 3 || n < 3) {
			ans = 0;
			int now = max(m, n);
			while (now > 0) {
				ans += min(now, 2) * 2;
				now -= 4;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}