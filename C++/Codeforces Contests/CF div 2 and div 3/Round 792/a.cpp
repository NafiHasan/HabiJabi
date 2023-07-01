#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.rbegin(), a.rend());
		long long needed = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i == 0)
				needed += 2LL * a[i] + 1;
			else needed += a[i] + 1;
		}
		needed++;
		if (needed <= m)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}