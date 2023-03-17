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
		string s;
		cin >> s;
		int ln = k + 2;
		string t = "RGB";
		while (t.size() < ln)t += t;
		while (t.size() > ln)t.pop_back();
		int ans = n + 1;
		for (int i = 0; i <= n - k; i++) {
			string tmp1 = s.substr(i, k);
			for (int j = 0; j < 3; j++) {
				string tmp2 = t.substr(j, k);
				int ch = 0;
				// cout << tmp1 << ' ' << tmp2 << '\n';
				for (int k = 0; k < tmp1.size(); k++) {
					if (tmp1[k] != tmp2[k])ch++;
				}
				ans = min(ans, ch);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}