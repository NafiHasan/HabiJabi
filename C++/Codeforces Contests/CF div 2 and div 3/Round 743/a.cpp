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
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != '0') {
				ans += (s[i] - '0') + 1;
			}
		}
		ans += s[n - 1] - '0';
		cout << ans << '\n';
	}
	return 0;
}