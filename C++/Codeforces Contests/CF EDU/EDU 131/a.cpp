#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a[2][2];
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1)cnt++;
			}
		}
		if (cnt == 4) {
			cout << "2\n";
		} else if (cnt == 0) {
			cout << "0\n";

		} else cout << "1\n";
	}
	return 0;
}