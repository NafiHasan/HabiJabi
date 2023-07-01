#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long c, d;
		cin >> c >> d;
		if ((c + d) % 2 ) {
			cout << "-1\n";
		} else if (c == d && c == 0)cout << "0\n";
		else if (c == d)cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}