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
		long long ans = 1LL;
		for (int i = 0; i < n; ++i )
			ans = ans * (a[i] + 1) % 1000000007;
		cout << ans - 1 << "\n";
	}
	return 0;
}