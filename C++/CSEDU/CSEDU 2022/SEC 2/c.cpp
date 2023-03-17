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
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				int dv = a[i] / a[i - 1];
				if (a[i] % a[i - 1] != 0)dv++;
				if (dv > 2) {
					int tmp = a[i - 1];
					int cnt = 0;
					while (tmp < a[i]) {
						cnt++;
						// cout << tmp << ' ' << a[i] <<  ' ' << a[i - 1] << '\n';
						tmp *= 2;
					}
					if (cnt > 0 )ans += cnt - 1;
				}
			} else if (a[i] < a[i - 1]) {
				int dv = a[i - 1] / a[i];
				if (a[i - 1] % a[i] != 0)dv++;
				if (dv > 2) {
					int tmp = a[i];
					int cnt = 0;
					while (tmp < a[i - 1]) {
						cnt++;
						tmp *= 2;
					}
					if (cnt != 0)ans += cnt - 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}