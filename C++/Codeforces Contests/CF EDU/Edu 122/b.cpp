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
		if (n <= 2) {
			cout << "0\n";
			continue;
		}
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')cnt0++;
			else cnt1++;
		}
		if (cnt1 == cnt0) {
			cout << cnt0 - 1 << '\n';
			continue;
		} else {
			cout << min(cnt1 , cnt0) << '\n';
		}
	}
	return 0;
}