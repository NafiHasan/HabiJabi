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
		string r1, r2;
		cin >> r1 >> r2;
		int ans = 0;
		for (int i = 0; i < n ; i++) {
			if (r1[i] == '0' && r2[i] == '0')ans++;
			else if (r1[i] != r2[i])ans += 2;
		}
		for (int i = 0; i < n; i++) {
			if (i == 0 && n > 1) {
				if (r1[i] == '1' && r2[i] == '1' && r1[1] == '0' && r2[1] == '0') {
					ans++;
					r1[1] = '2' ; r2[1] = '2';
				}
			} else if (i == n - 1 && i > 0) {
				if (r1[i] == '1' && r2[i] == '1' && r1[i - 1] == '0' && r2[i - 1] == '0') {
					ans++;
					r1[i - 1] = '2' ; r2[i - 1] = '2';
				}
			} else if (i > 0 && i < n - 1 && r1[i] == '1' && r2[i] == '1') {
				if (r1[i - 1] == '0' && r2[i - 1] == '0' ) {
					ans++;
					r1[i - 1] = '2'; r2[i - 1] = '2';
				} else if (r1[i + 1] == '0' && r2[i + 1] == '0') {
					ans++;
					r1[i + 1] = '2' ; r2[i + 1] = '2';
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}