#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<int> a(n), pre(32770, 20);
	for (int i = 2; i <= 32768; i += 2) {
		int cnt = 0;
		int tmp = i;
		while (tmp % 2 == 0) {
			cnt++;
			tmp /= 2;
		}
		pre[i] = cnt;
		// cout << i << ' ' << pre[i] << '\n';
	}
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<int> ans(n, 20);
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			ans[i] = 0;
			continue;
		}
		ans[i] = min(ans[i], 32768 - a[i]);
		for (int j = a[i], k = 0; j <= a[i] + 16; k++, j++) {
			if (pre[j] < 20)ans[i] = min(ans[i], 15 - pre[j] + k);
		}
	}
	for (int i = 0; i < n; i++)cout << ans[i] << ' ';
	cout << "\n";
	return 0;
}