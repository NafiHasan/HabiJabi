#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll hc, dc, hm, dm, k, arm, hel;
		cin >> hc >> dc >> hm >> dm >> k >> arm >> hel;
		ll hero, vil;
		bool ans = 0;
		for (ll i = 0; i <= k; i++) {
			ll thc = hc + (i * hel);
			ll tdc = dc + ((k - i) * arm);
			hero = hm / tdc;
			if (hm % tdc != 0)hero++;
			vil = thc / dm;
			if (thc % dm != 0)vil++;
			if (hero <= vil) {
				ans = 1;
				break;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}