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
		long long x, y;
		cin >> x >> y;
		if (x == 1 && y == 1) {
			cout << "NO\n";
			continue;
		} else if (y == 1) {
			cout << "NO\n";
			continue;
		}
		// if (x == y) {
		// 	cout << "NO\n";
		// 	continue;
		// }
		cout << "YES\n";
		cout << x << " " << y*x << " " << x + (x * y) << en;
		// else cout << y << " " << y * x << " " << y + (y * x) << en;
	}
	return 0;
}