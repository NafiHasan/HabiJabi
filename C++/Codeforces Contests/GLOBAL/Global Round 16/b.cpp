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
		int ans = 0, z = 1;
		for (int i = 0; i < n; i++) {
			if (z && s[i] == '0') {
				z = 0;
				ans++;
			} else if (s[i] == '1') {
				z = 1;
			}
		}
		cout << min(ans, 2) << '\n';
	}
	return 0;
}