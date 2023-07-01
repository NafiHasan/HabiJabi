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
		long long a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans, a[i] * a[i + 1]);
		}
		cout << ans << "\n";
	}
	return 0;
}