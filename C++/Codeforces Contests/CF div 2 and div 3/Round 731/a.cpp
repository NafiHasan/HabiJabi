#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int xa, xb, ya, yb, fa, fb;
		cin >> xa >> ya >> xb >> yb >> fa >> fb;
		int ans = abs(xa - xb) + abs(ya - yb);
		if ((xa == xb && xa == fa && fb >= min(ya, yb) && fb <= max(ya, yb)) || (ya == yb && ya == fb && fa >= min(xa, xb) && fa <= max(xa, xb)))ans += 2;
		cout << ans << "\n";
	}
	return 0;
}