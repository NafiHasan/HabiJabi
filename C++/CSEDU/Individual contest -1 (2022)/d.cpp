#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		int pre[n + 1][30];
		memset(pre, 0 , sizeof(pre));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				if (j == s[i] - 'a')pre[i + 1][j] = pre[i][j] + 1;
				else pre[i + 1][j] = pre[i][j];
			}
		}
		while (q--) {
			int l, r;
			cin >> l >> r ;
			char c;
			cin >> c;
			int ch = c - 'a';
			l--;
			int ans = (pre[l % n][ch] - pre[0][ch]) + ((pre[n][ch] - pre[0][ch]) * (l / n));
			int cnt2 = (pre[r % n][ch] - pre[0][ch]) + ((pre[n][ch] - pre[0][ch]) * (r / n));
			cout << cnt2 - ans << "\n";
		}
	}
	return 0;
}