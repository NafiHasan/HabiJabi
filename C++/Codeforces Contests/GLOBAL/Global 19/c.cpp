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
		bool ys = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0 && i < n - 1 && a[i] > 1)ys = 1;
		}
		if (n == 3 && a[1] % 2)ys = 0;
		long long ans = 0;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] % 2)ans += (a[i] + 1) / 2;
			else ans += a[i] / 2;
		}
		if (!ys)ans = -1;
		cout << ans << '\n';
	}
	return 0;
}