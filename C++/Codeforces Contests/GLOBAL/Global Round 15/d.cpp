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
		int a[n + 1];
		for (int i = 0; i < n; i++)cin >> a[i];
		a[n] = 0;
		int num = pow(2, n + 1) - 1;
		bool found = 0;
		for (int i = 0; i < n && !found; i++) {
			int cur = num;
			cur ^= (1 << i);
			// cout << cur << "\n";
			for (int j = 0; j < n && !found; j++) {
				if ((cur & (1 << j)) == 0)continue;
				cur ^= (1 << j);
				// cout << cur << " " << (1 << j) << "\n";
				for (int k = 0; k <= n && !found; k++) {
					if ((cur & (1 << k)) == 0)continue;
					cur ^= (1 << k);
					for (int l = 0; l <= n && !found; l++) {
						if ((cur & (1 << l)) == 0)continue;
						if (a[i] - a[l] == a[j] - a[k]) {
							found = 1;
							cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << "\n";
						}
						if (a[i] - a[k] == a[j] - a[l]) {
							found = 1;
							cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << "\n";
						}
					}
				}
			}
		}
		if (found)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}