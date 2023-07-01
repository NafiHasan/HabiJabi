#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		ll n, x, t ;
		cin >> n >> x >> t ;
		ll p = min((n - 1), t / x);
		ll ans = (n - p - 1) * p;
		ans += p * (p + 1) / 2;
		cout << max(0LL, ans) << en;
	}
	return 0;
}