#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		ll n;
		cin >> n;
		ll ans = 0;
		if ((n & (n - 1)) == 0 )ans = n;
		else {
			ll i = 0;
			ll cnt = 0;
			while (cnt < n) {
				ans = cnt;
				cnt = (1 << i);
				i++;
			}
		}
		cout << ans - 1 << en;
	}
	return 0;
}