#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	// cout << 454 % 11 << en;
	w(t) {
		ll x;
		cin >> x;
		ll mod = x % 11;
		if (x >= mod * 111)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}