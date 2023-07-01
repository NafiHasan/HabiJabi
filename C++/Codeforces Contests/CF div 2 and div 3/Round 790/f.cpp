#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), has;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			if (m[a[i]] == k)has.push_back(a[i]);
		}
		sort(has.begin(), has.end());
		int l = -1, r = -1, tmpl, tmpr;
		int ans = 0, cur = 0;
		if (has.size() >= 1) {
			tmpl = has[0];
			l = has[0], r = has[0];
		}
		for (int i = 1; i < has.size(); i++) {
			if (has[i] == has[i - 1] + 1) {
				cur++;
				tmpr = has[i];
			} else {
				if (cur > ans) {
					l = tmpl;
					r = tmpr;
					ans = cur;
				}
				cur = 0;
				tmpl = has[i];
			}
		}
		if (cur > ans) {
			l = tmpl;
			r = tmpr;
		}
		if (l == -1 && r == -1)cout << "-1\n";
		else cout << l << ' ' << r << '\n';
	}
	return 0;
}