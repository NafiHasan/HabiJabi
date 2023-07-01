#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int ans = 0;
		if (k == 1)ans = (n - 1) / 2;
		else {
			for (int i = 1; i < n - 1; i++) {
				if (a[i] > a[i - 1] + a[i + 1])ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}