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
		if (n % 2050)cout << "-1\n";
		else {
			ll sum = n / 2050;
			ll ans = 0;
			while (sum) {
				ans += sum % 10;
				sum /= 10;
			}
			cout << ans << en;
		}
	}
	return 0;
}