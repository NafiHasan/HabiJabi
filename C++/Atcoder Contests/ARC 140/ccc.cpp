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
		string s;
		cin >> s;
		vector<int> cnt[26], precnt(26, 0);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				precnt[s[i] - 'a']++;
			} else if (s[i] == s[i - 1]) {
				precnt[s[i] - 'a']++;
			} else {
				precnt[s[i] - 'a']++;
				// for (int i = 0; i < 26; i++) {
				// cout << s[i] << ' ' << s[i - 1] << '\n';
				if (precnt[s[i - 1] - 'a'] > 0) {
					cnt[s[i - 1] - 'a'].push_back(precnt[s[i - 1] - 'a']);
					precnt[s[i - 1] - 'a'] = 0;
				}
				// }
			}
		}
		// cout << cnt[0].size() << '\n';
		for (int i = 0; i < 26; i++) {
			if (precnt[i] > 0) {
				cnt[i].push_back(precnt[i]);
				precnt[i] = 0;
			}
		}
		for (int i = 0; i < 26; i++)sort(cnt[i].rbegin(), cnt[i].rend());
		vector<vector<int>> presum(26, vector<int>(n + 1, 0));
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j <= n ; j++) {
				int add = 0;
				if (j < cnt[i].size()) {
					add = cnt[i][j];
				}
				if (j == 0) {
					if (cnt[i].size() >= 1) presum[i][j] = cnt[i][0];
				} else {
					presum[i][j] = presum[i][j - 1] + add;
				}
			}
		}
		// for (int i = 0; i < cnt[1].size(); i++) {
		// 	cout << cnt[1][i] << ' ';
		// }
		// cout << '\n';
		for (int i = 0; i <= n; i++) {
			int mx = 0;
			for (int j = 0; j < 26; j ++) {
				mx = max(mx, presum[j][i]);
			}
			cout << mx << ' ' ;
		}
		cout << '\n';
	}
	return 0;
}