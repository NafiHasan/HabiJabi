#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0\n";
			continue;
		}
		if (b > a) {
			int dif = b - a;
			if ((b - a) % 2 == 1)cout << "1\n";
			else if ((dif / 2) % 2 == 0 )cout << "3\n";
			else cout << "2\n";
		} else {
			if ((a - b) % 2 == 0)cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}