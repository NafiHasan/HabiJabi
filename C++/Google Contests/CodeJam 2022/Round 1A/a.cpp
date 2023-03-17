#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		string s, ans = "";
		cin >> s;
		bool sam = 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[0])sam = 0;
		}
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] < s[i + 1]) {
				ans += s[i];
				ans += s[i];
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == s[i])ans += s[j];
					else break;
				}
			} else ans += s[i];
		}
		ans += s[s.size() - 1];
		if (sam)ans = s;
		cout << "Case #" << cs << ": " << ans << "\n";
	}
	return 0;
}