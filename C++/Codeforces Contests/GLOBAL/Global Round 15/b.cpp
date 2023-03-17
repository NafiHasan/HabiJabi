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
		int a[n][5];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> a[i][j];
			}
		}
		int ans = -1, cur  = 0;;
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (a[i][j] < a[cur][j])cnt++;
			}
			if (cnt > 2)cur = i;
		}
		ans = cur + 1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (a[i][j] < a[cur][j])cnt++;
			}
			if (cnt > 2) {
				ans = -1;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}