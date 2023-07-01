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
		int mx = 0;
		while (n > 0) {
			mx = max(mx, n % 10);
			n /= 10;
		}
		cout << mx << "\n";
	}
	return 0;
}