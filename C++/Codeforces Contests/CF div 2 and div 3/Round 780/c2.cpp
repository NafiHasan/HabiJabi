#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = s.size();
		map<char, int> m;
		// for (int i = 0; i < n; i++)m[s[i]]++;
		int cnt = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			m[s[i]]++;
			cnt++;
			if (m[s[i]] > 1) {
				m.clear();
				ans += cnt - 2;
				cnt = 0;
			}
		}
		ans += cnt;
		cout << ans << '\n';
	}
	return 0;
}