#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		bool ans = 1;
		for (int i = 0, j = 0; i < t.size(); i++) {
			while (j < s.size() && s[j] != t[i])j += 2;
			if (j >= s.size()) {
				ans = 0;
				break;
			}
			j++;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}