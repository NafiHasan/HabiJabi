#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		ll ans = 1, mn = LLONG_MAX;
		for (int i = 1; i < n; i++) {
			mn = min(mn, abs(a[i] - a[i - 1]));
			if (a[i] > mn)break;
			ans++;
		}
		cout << ans << en;
	}
	return 0;
}