#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++)cin >> a[i];
		bool ans = 1;
		for (int i = 2; i <= n ; i++) {
			if (a[i] == a[i - 1])continue;
			if (a[i - 1] != 0 && a[i] % a[i - 1] == 0)continue;
			bool f = 0;
			for (int j = 1; j * j <= a[i]; j++) {
				if (a[i] % j == 0) {

					int d1 = a[i] / j, d2 = j;
					if (a[i - 1] > d1 && (a[i - 1] - d1) % a[i - 2] == 0) {
						f = 1;
						break;
					}
					if (a[i - 1] > d2 && (a[i - 1] - d2) % a[i - 2] == 0) {
						f = 1;
						break;
					}
				}

			}
			if (f == 0) {
				ans = 0;
				break;
			}
			// if (a[i] - a[i - 1] > 0 && a[i + 1] % (a[i] - a[i - 1]) != 0) {
			// 	ans = 0;
			// 	break;
			// }
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}