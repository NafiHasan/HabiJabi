#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b , c;
		cin >> a >> b >> c;
		int dif = abs(a - b);
		int lim = dif * 2;
		if (c > lim || a > lim || b > lim) {
			cout << "-1\n";
			continue ;
		}
		if (c + dif > lim) {
			if (c > dif)cout << c - dif << "\n";
			else cout << "-1\n";
		} else {
			cout << c + dif << "\n";
		}
	}
	return 0;
}