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
		map<ll, ll>m;
		for (int i = 0; i < n; i++)cin >> a[i] ;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll fi = i + 1, se = n - i;
			ans += m[a[i]] * se;
			m[a[i]] += fi;
		}
		cout << ans << en;
	}
	return 0;
}