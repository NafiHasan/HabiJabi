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
		map<int, int> m;
		int n = s.size();
		string ans = s;
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < n; i++) {
			m[s[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (m[s[i]] > 1) {
				m[s[i]]--;
				ans.pop_back();
			} else break;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}