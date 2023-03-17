#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, b, x, y;
		cin >> n >> b >> x >> y;
		vector<ll> a(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] + x > b) {
				a[i] = a[i - 1] - y;
			} else a[i] = a[i - 1] + x;
		}
		ll sum = 0;
		for (int i = 0; i <= n; i++) {
			sum += a[i];
		}
		cout << sum << '\n';
	}
	return 0;
}