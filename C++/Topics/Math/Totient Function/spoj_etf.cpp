#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int phi(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans -= ans / i;
		}
	}
	if (n > 1) {
		ans -= ans / n;
	}
	return ans;
}



signed main() {
	FastIO;
	int tc;
	cin >> tc;
	int mx = 0;
	while (tc--) {
		int a, m;
		cin >> a ;
		// m /= __gcd(a, m);
		int ans = phi(a);
		mx = max(ans, mx);
		cout << ans << '\n';
	}
	cout << mx << '\n';
	return 0;
}