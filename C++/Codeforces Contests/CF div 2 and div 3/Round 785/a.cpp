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
		if (s.size() == 1) {
			cout << "Bob ";
		} else cout << "Alice ";
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			ans += s[i] - 'a' + 1;
		}
		int cnt = 0;
		if (s.size() > 1 && s.size() % 2 == 1) {
			int mn = min(s[0] - 'a' + 1, s.back() - 'a' + 1);
			cnt = ans - mn;
			ans = cnt - mn;
		}
		cout << ans << '\n';
	}
	return 0;
}