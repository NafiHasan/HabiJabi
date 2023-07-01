#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n ;
		string s;
		cin >> s;
		bool found = 0;
		string ans = "";
		vector<int>v(12, 0);
		for (int i = 0; i < n; i++) {
			v[s[i] - '0']++;
			if (s[i] == '4' || s[i] == '6' || s[i] == '1' || s[i] == '8' || s[i] == '9') {
				found = 1;
				ans = s[i];
				break;
			}
		}
		if (!found) {
			for (int i = 1; i <= 9; i++) {
				if (v[i] > 1) {
					ans = to_string(i * 10 + i);
					found = 1;
					break;
				}
			}
		}
		if (!found) {
			int cnt = 0;
			char pr[] = {'2', '5', '7'};
			for (int i = 0; i < n; i++) {
				if (cnt >= 2)break;
				for (int j = 0; j < 3; j++) {
					if (s[i] == pr[j]) {
						ans += pr[j];
						cnt++;
					}
				}
			}
			if (cnt < 2) {
				ans = s;
			}
			// if (v[2] > 0) {
			// 	ans += '2';
			// 	cnt++;
			// }
			// if (v[5] > 0) {
			// 	ans += '5';
			// 	cnt++;
			// }
			// if (v[7] > 0 && cnt < 2) {
			// 	ans += '7';
			// }
		}
		cout << ans.size() << '\n';
		cout << ans << '\n';
	}
	return 0;
}