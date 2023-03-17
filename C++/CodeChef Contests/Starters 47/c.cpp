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
		int pre = 2;
		bool ans = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (i % 2 == 1) {
				string s1 = s.substr(0, (i + 1) / 2);
				string s2 = s.substr((i + 1) / 2, (i + 1) / 2);
				if ( s1 != s2) {
					ans = 0;
					break;
				} else {
					i = i / 2 + 1;
				}
				pre = 2;
			} else if (i % 2 == 0 && pre == 2) {
				pre = 1;
			} else {
				ans = 0;
				break;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}