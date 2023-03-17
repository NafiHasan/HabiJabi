#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c, m;
		cin >> a >> b >> c >> m;
		if (a + b + c - 3 < m) {
			cout << "NO\n";
			continue;
		}
		if (a < b)swap(a, b);
		if (b < c) {
			swap(b, c);
			if (a < b) swap(a, b);
		}
		if (b + c + 1 >= a) {
			cout << "YES\n";
			continue;
		}
		if (b + c + m + 1 >= a)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}