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
		vector<long long> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		long long ans = 0, prev = a[0], next = 0;
		for (int i = 1; i < n; i++) {
			a[i] -= next;
			if (a[i] == prev)continue;
			if (a[i] < prev) {
				ans += prev - a[i];
				prev = a[i];

			} else {
				ans += a[i] - prev;
				next += a[i] - prev;
			}
		}
		ans += abs(prev);
		cout << ans << '\n';
	}
	return 0;
}