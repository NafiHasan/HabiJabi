#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, k;
		cin >> n >> k;
		vector<long long>v(n);
		for (int i = 0; i < n ; i++) cin >> v[i];
		long long ans = LLONG_MIN;
		for (long long i = max(0LL, n - 1000); i < n - 1; i++) {
			for (long long j = i + 1; j < n; j++) {
				long long temp = (i + 1LL) * (j + 1LL) ;
				temp -= k * (v[i] | v[j]);
				ans = max(ans, temp);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}