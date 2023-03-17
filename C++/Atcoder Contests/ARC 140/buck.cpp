#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int w, x, y, z;
		cin >> w >> x >> y >> z;
		int in = y * z;
		if (w + in > x) {
			cout << "overFlow\n";
		} else if (w + in < x) {
			cout << "Unfilled\n";
		} else cout << "filled\n";
	}
	return 0;
}