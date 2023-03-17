#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll x , y ;
		cin >> x >> y;
		ll last1 = 1, last2 = y;
		for (ll i = 2; i * i <= y; i++) {
			if (y % i == 0) {
				last1 = i, last2 = y / i;
			}
		}
		ll mn = 2LL * (last1 - 1LL), mx = 2LL * (last2 + 1LL);
		if (x > mn && x < mx) {
			cout << "-1\n";
			continue;
		}
		ll f1 , f2;
		if (x <= mn) {
			f1 = last1 - 1LL;
			f2 = x - f1;
			if (f2 < 0) {
				f2 += f1;
				f1 = 0;
			}
			if (f1 > f2)swap(f1, f2);
		} else {
			f1 = last2  + 1LL;
			f2 = x - f1;
			if (f1 > f2)swap(f1, f2);
		}
		cout << last1 << ' ' << last2 << '\n';
		cout << f1 << ' ' << f2 << '\n';

	}
	return 0;
}