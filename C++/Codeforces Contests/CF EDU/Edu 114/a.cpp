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
		string ba = "()";
		string s = "";
		for (int i = 0; i < n; i++)s += ba;
		cout << s << '\n';
		for (int i = 1; i < 2 * n - 1; i += 2) {
			string tmp = s;
			tmp[i] = '(';
			tmp[i + 1] = ')';
			cout << tmp << '\n';
		}

	}
	return 0;
}