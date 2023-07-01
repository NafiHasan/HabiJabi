#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0, cnt = 0, pre = -1;
		for (int i = 0; i < n; i++) {
			if (pre == -1 && s[i] == '0') {
				pre = i;
				cnt = 0;
			} else if (pre > -1 && s[i] == '0') {
				ans += max(0, 2 - cnt);
				pre = i;
				cnt = 0;
			} else if (s[i] == '1') {
				cnt++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}