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
		long long ans = 0;
		for (int i = 0; i < 22; i++) {
			bool add = 0;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (((1 << i) & a[j]) != 0) {
					if (add) cnt++;
					else {
						add = 1;
						cnt++;
					}
				} else if (add) {
					long long tmp = (long long)cnt * (long long)(cnt + 1) / 2LL;
					long long tmp2 = (1 << i);
					ans += tmp * tmp2;
					cnt = 0;
				}
			}
			if (add) {
				long long tmp = (long long)cnt * (long long)(cnt + 1) / 2LL;
				long long tmp2 = (1 << i);
				ans += tmp * tmp2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}