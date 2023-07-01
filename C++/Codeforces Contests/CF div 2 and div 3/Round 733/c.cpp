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
		int a[n], req[n], sum = 0, need = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> req[i];
			need += req[i];
		}

		sort(a, a + n, greater<int>());
		sort(req, req + n, greater<int>());
		vector<int>csum(n + 1, 0), cneed(n + 1, 0);
		for (int i = 0; i < n; i++) {
			csum[i + 1] = csum[i] + a[i];
			// cout << csum[i + 1] << " " ;
		}
		for (int i = 0; i < n; i++) {
			cneed[i + 1] = cneed[i] + req[i];
			// cout << csum[i + 1] << " " ;
		}
		if (csum[n - (n / 4)] >= cneed[n - (n / 4)]) {
			cout << "0\n";
			continue;
		}
		// cout << "\n";
		int ans = need / 100;
		if (need % 100 != 0)ans++;
		ans += n;
		// cout << ans << "\n";
		while (1) {
			ans--;
			if (ans < n) {
				ans++;
				break;
			}
			int tot = ans - (ans / 4);
			int all = 100 * max(0, (ans - n));
			all += csum[max(0, tot - ans + n)];
			need = cneed[min(tot, n)];
			if (all < need) {
				// cout << all << " " << need << "\n";
				ans++;
				break;
			}
		}
		cout << ans - n << "\n";
	}
	return 0;
}