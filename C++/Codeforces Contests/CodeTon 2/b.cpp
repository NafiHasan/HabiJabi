#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		ll mn = a[0], mx = a[0];
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			mn = min(a[i], mn);
			mx = max(a[i], mx);
			if (mx - mn > 2LL * x) {
				cnt++;
				mn = a[i], mx = a[i];
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}