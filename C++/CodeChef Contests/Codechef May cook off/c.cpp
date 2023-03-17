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
		if (n == 1)cout << "1\n";
		else if (n <= 3 || n % 2 == 1)cout << (n - 1) << '\n';
		else cout << n << '\n';
	}
	return 0;
}