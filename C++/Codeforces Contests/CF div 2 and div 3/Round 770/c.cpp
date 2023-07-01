#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		if (k == 1) {
			cout << "YES\n";
			for (int i = 1; i <= (n * k); i++) {
				cout << i << '\n';
			}
			continue;
		}
		if (n % 2)cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 1; i <= n; i++) {
				int now = i;
				for (int j = 1; j <= k; j++) {
					cout << now << ' ';
					now += n;
				}
				cout << '\n';
			}
		}
	}
	return 0;
}