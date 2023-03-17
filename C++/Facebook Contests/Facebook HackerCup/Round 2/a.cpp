#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int>> a(30, vector<int> (n + 5, 0));
		for (int i = 0; i < n; i++) {
			a[(s[i] - 'a')][i + 1]++;
			for (int j = 0; j < 26; j++) {
				a[j][i + 1] += a[j][i];
			}
		}
		int q, ans = 0;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;
			if ((r - l) % 2 == 1)continue;
			if (r == l) {
				ans++;
				continue;
			}
			int odd = 0, od = -1, odpos = -1, odcnt = 0;
			for (int j = 0; j < 26; j++) {
				if ((a[j][r] - a[j][l - 1]) % 2) {
					odd++;
					odcnt = a[j][r] - a[j][l - 1];
					od = j;
				}
			}
			if (odd > 1)continue;
			int mid = (l + r) / 2;
			bool ok = 1;
			for (int i = 0; i < 26 && odcnt == 1; i++) {
				if (i == od) {
					continue;
				}
				if ((a[i][mid - 1] - a[i][l - 1]) == (a[i][r] - a[i][mid]) && (s[mid - 1] - 'a') == od) {
					continue;
				} else if ((a[i][mid] - a[i][l - 1]) == (a[i][r] - a[i][mid])) {
					continue;
				} else if ((a[i][mid - 1] - a[i][l - 1]) == (a[i][r] - a[i][mid - 1])) {
					continue;
				} else {
					ok = 0;
					break;
				}
			}
			int ald = 1;
			for (int i = 0; i < 26 && odcnt > 1; i++) {
				if ((a[i][mid - 1] - a[i][l - 1]) == (a[i][r] - a[i][mid]) && (s[mid - 1] - 'a') == od) {
					continue;
				} else if ((a[i][mid] - a[i][l - 1]) == (a[i][r] - a[i][mid])) {
					continue;
				} else if ((a[i][mid - 1] - a[i][l - 1]) == (a[i][r] - a[i][mid - 1])) {
					continue;
				} else if (((a[i][mid - 1] - a[i][l - 1]) == (a[i][r] - a[i][mid - 1] + 1))  || ((a[i][mid - 1] - a[i][l - 1] + 1) == (a[i][r] - a[i][mid - 1]))) {
					if (ald == 1) {
						ald--;
					} else {
						ok = 0;
						break;
					}
				} else {
					ok = 0;
					break;
				}
			}

			if (ok) {
				ans++;
				// cout << l << ' ' << r << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
}