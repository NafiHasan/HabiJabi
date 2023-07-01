#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		if (m < n || (n % 2 == 0 && m % 2 == 1))cout << "No\n";
		else {
			cout << "Yes\n";
			int lim  = n - 1;
			if (lim % 2 == 1) lim--;
			for (int i = 1; i <= lim; i++) {
				cout << "1 ";
			}
			if (lim == n - 2) {
				cout << (m - lim) / 2 << ' ' << (m - lim) / 2 << '\n';
			} else cout << (m - lim) << '\n';
		}
	}
	return 0;
}