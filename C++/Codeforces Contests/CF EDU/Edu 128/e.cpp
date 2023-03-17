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
		string s1, s2;
		cin >> s1 >> s2;
		int total = 0, ans = 0, t1 = 0, t2 = 0, last1 = -1, last2 = -1, last = 0, ind = -1, st1 = -1, st2 = -1;
		for (int i = 0; i < n; i++) {
			if (ind == -1 and (s1[i] == '*' or s2[i] == '*'))ind = i;
			if (s1[i] == '*') {
				total++;
				t1++;
				last1 = i;
				if (st1 == -1)st1 = i;

			}
			if (s2[i] == '*') {
				total++;
				t2++;
				last2 = i;
				if (st2 == -1)st2 = i;
			}

		}
		last = max(last1, last2);
		bool ri = 0;
		if (st1 != -1 && last1 >= last2)ri = 1;
		else if (st2 != -1 && last2 >= last1) ri = 1;
		while (last > ind) {
			ans++;
			// if (s1[last] == '*' && s2[last] == '*')ans++;
			if (!ri) {
				if (last1 >= last2) {
					if (s2[last] == '*') {
						ans++;
						ri = 1;
					}
				} else {
					if (s1[last] == '*') {
						ans++;
						ri = 1;
					}
				}
			} else {
				if (last1 >= last2) {
					if (s2[last] == '*') {
						ans++;
						ri = 1;
					}
				} else {
					if (s1[last] == '*') {
						ans++;
						ri = 1;
					}
				}
			}
			last--;
		}
		if (!ri)ans++;
		if (s1[last] == s2[last])ans++;
		cout << ans << '\n';
	}
	return 0;
}