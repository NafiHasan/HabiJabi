#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		ll r, b, d;
		cin >> r >> b >> d;
		if (r > b)swap(r, b);
		ll div = b / r;
		if (b % r)div++;
		if (div - 1 > d)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}