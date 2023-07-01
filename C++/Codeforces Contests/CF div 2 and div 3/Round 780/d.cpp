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
			if (a[i] != 0)cnt[a[i] + 2]++;
			if (a[i] == 0 || i == n - 1) {
				v.push_back(cnt);
				cnt = tmp;
			}
		}
		// if (cnt != tmp) {
		// 	v.push_back(cnt);
		// }
		if (v.size() == 0) {
			cout << n << ' ' << 0 << '\n';
			continue;
		}
		// cout << "hel";
		int f = 0, l = 0;
		int mx = 0, mx2 = 0, mxm2 = 0;
		int cumf = 0;
		for (int i = 0; i < v.size(); i++) {
			// if (v[i] == tmp)cumf++;
			if (mx < v[i][0] + v[i][4]) {
				mx = v[i][0] + v[i][4];
				mx2 = v[i][4], mxm2 = v[i][0];
				f = cumf + i;
				int tm = 0;
				for (int j = 0; j < 5; j++) {
					tm += v[i][j];
				}
				l = n - tm - f;
			} else if (mx == v[i][0] + v[i][4] && v[i][0] + v[i][1] % 2 == 0) {
				if (mx2 < v[i][4]) {
					mx2 = v[i][4], mxm2 = v[i][0];
					f = cumf + i;
					int tm = 0;
					for (int j = 0; j < 5; j++) {
						tm += v[i][j];
					}
					l = n - tm - f;
				}
			}
			for (int j = 0; j < 5; j++) {
				cumf += v[i][j];
			}
		}
		if (mx == 0) {
			cout << n << ' ' << 0 << '\n';
			continue;
		}
		// cout << f << ' ' << l << '\n';
		int cntm = 0, cntt2 = 0;
		for (int i = f; i < n - l; i++) {
			tmp[a[i] + 2]++;
			if (a[i] < 0)cntm++;
		}
		if (cntm % 2 == 0) {
			cout << f << ' ' << l << '\n';
			continue;
		}
		int pass = 0;
		cntm = n + 1;
		int tmpf = f, tmpl = l, mincnt2 = n + 1;
		for (int i = f; i < n - l; i++) {
			pass++;
			if (a[i] == -2 || a[i] == 2)cntt2++;
			if (a[i] < 0) {
				cntm = min(cntm, pass);
				mincnt2 = min(mincnt2, cntt2);
				tmpf += pass;
				break;
			}
		}
		pass = 0;
		cntt2 = 0;
		for (int i = n - l - 1; i >= f; i--) {
			pass++;
			if (a[i] == -2 || a[i] == 2)cntt2++;
			if (a[i] < 0 && mincnt2 > cntt2) {
				tmpf = f;
				tmpl += pass;
				break;
			}
		}
		cout << tmpf << ' ' << tmpl << '\n';
	}
	return 0;
}