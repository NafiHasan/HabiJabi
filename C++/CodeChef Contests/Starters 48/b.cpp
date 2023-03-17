#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		if (n % 2 == 0 && m % 2 == 0) cout << "0\n";
		else if (n % 2 == 1 && m % 2 == 1)cout << n + m  - 1 << '\n';
		else if (n % 2 == 1)cout << m << '\n';
		else cout << n << '\n';
	}
	return 0;
}