#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << en;
			continue;
		} else if (n == 2) {
			cout << "-1\n";
			continue;
		} else {
			int a[n][n];
			int cnt = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j % 2) {
						if (i < n - 1) a[i + 1][j] = cnt++;
						else a[0][j] = cnt++;
					} else a[i][j] = cnt++;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)cout << a[i][j] << " ";
				cout << en;
			}
		}
	}
	return 0;
}