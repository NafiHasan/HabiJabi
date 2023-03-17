#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		int n;
		cin >> n;
		cin >> s;
		int a = -1, b = -1;
		for (int i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				a = i, b = i + 1;
				break;
			}
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}