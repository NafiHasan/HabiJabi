#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int r, c, m, n;
		cin >> r >> c >> m >> n;
		vector<int> a(26, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char ch;
				cin >> ch;
				a[ch - 'A']++;
			}
		}
		int mx = 0;
		for (int i = 0; i < 26; i++) {
			mx = max(mx, a[i]);
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			if (a[i] == mx)ans += a[i] * m;
			else ans += a[i] * n;
		}
		cout << "Case " << cs << ": " << ans << '\n';
	}
	return 0;
}