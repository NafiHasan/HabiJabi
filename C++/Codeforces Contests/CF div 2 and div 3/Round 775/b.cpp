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
		sort(a.begin(), a.end());
		long long sum = 0;
		for (int i = 0; i < n - 1; i++)sum += a[i];
		long long ans = max(1LL, a[n - 1] - sum);
		if (sum + a[n - 1] == 0)ans = 0;
		cout << ans << '\n';
	}
	return 0;
}