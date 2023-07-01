#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		vector<long long> v(n - 1);
		for (int i = 1; i < n; i++)v[i - 1] = a[i] - a[i - 1];
		long long ans = 0;
		for (long long i = 0; i < n - 1; i++) {
			long long right = (n - 2 - i);
			long long tot = ((i + 1) * right) + i;
			ans += tot * v[i];
		}
		cout << -1LL * ans << en;
	}
	return 0;
}