
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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		for (int i = 0; i < n; i++) {
			int t1 = a[i], t2 = b[i];
			a[i] = min(t1, t2);
			b[i] = max(t1, t2);
		}
		// for (int i = 0; i < n; i++)cout << a[i] << ' ';
		// cout << "\n";
		// for (int i = 0; i < n; i++)cout << b[i] << ' ';
		// cout << "\n";
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			ans += (long long)abs(a[i] - a[i - 1]);
			ans += (long long)abs(b[i] - b[i - 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}