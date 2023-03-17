#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x + y <= z)cout << "2\n";
		else if (x <= z)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}