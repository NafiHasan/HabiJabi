#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			cout << "0\n";
			continue;
		}
		int sq =  x * x + y * y;
		int rt = sqrt(sq);
		if (rt * rt == sq) {
			cout << "1\n";
			continue;
		} else cout << "2\n";
	}
	return 0;
}