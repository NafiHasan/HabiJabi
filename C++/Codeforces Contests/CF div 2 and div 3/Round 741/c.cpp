#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int z = -1;
		int must = n / 2;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')z = i;
		}
		if (z == -1) {
			if (n % 2) {
				cout << 1 << ' ' << n - 1 << ' ' << 1 << ' ' << n / 2 << '\n';
			} else cout << 1 << ' ' << n << ' ' << 1 << ' ' << n  / 2 << '\n';
			continue;
		} else {
			if (z < must) {
				cout << z + 1 << ' ' << n << ' ' << z + 2 << ' ' << n << '\n';
			} else {
				cout << 1 << ' ' << z + 1 << ' ' << 1 << ' ' << z << '\n';
			}
		}
	}
	return 0;
}