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
		vector<int> a(n);
		vector<int> cnt(5, 0), tmp(5, 0);
		vector<vector<int>> v;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i] + 2]++;
			if (a[i] == 0 || i == n - 1) {
				v.push_back(cnt);
				cnt = tmp;
			}
		}
		int f = 0, l = 0, cumf = 0, cnt2 = 0, cntm = 0, mx = -1;
		for (int i = 0; i < v.size(); i++) {
			cnt2 = v[i][4] + v[i][0];
			cntm = v[i][0] + v[i][1];
			if (cntm % 2 == 0 && mx < cnt2) {
				mx = cnt2;
				f = cumf;
				int tm = 0;
				for (int j = 0; j < 5; j++) {
					if (j != 2)tm += v[i][j];
				}
				l = n - tm - f;
			} else if (cntm % 2 == 1) {
				int tm = 0;
				for (int j = 0; j < 5; j++) {
					if (j != 2)tm += v[i][j];
				}
				// cout << tm << '\n';
				int tm2 = 0, mn2 = n + 1;
				int tmpf = 0, tmpl = 0;
				// cout << cumf + i << ' ' << tm << '\n';
				for (int j = cumf , k = 1; k <= tm; k++, j++) {
					if (a[j] == 2 || a[j] == -2)tm2++;
					if (a[j] < 0) {
						mn2 = min(mn2, tm2);
						// l = n - j;
						tmpf = cumf + k;
						tmpl = (n - tm - cumf);
						// cout << tmpf << ' ' << tmpl << '\n';
						break;
					}
				}
				tm2 = 0;
				// cout << tm + cumf - 1 << '\n';
				// cout << cumf  << ' ' << tm << '\n';
				for (int j = tm + cumf - 1, k = 1; k <= tm ; k++, j--) {
					if (a[j] == 2 || a[j] == -2)tm2++;
					if (a[j] < 0 && mn2 > tm2) {
						mn2 = min(mn2, tm2);
						tmpf = cumf;
						tmpl = (n - tm - cumf) + k;
						break;
					}
				}
				if (mx < cnt2 - mn2) {
					mx = cnt2 - mn2;
					f = tmpf;
					l = tmpl;
				}
			}
			for (int j = 0; j < 5; j++) {
				cumf += v[i][j];
			}
		}
		cout << f << ' ' << l << '\n';
	}
	return 0;
}