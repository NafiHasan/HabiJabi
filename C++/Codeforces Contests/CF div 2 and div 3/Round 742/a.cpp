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
		string s, ans = "";
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'U')ans += 'D';
			else if (s[i] == 'D')ans += 'U';
			else ans += s[i];
		}
		cout << ans << '\n';
	}
	return 0;
}