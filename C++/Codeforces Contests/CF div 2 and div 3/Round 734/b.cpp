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
		// sort(s.begin(), s.end());
		map<char, int>m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		int ans = 0, cnt = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (m[i] >= 2)ans++;
			else if (m[i] == 1)cnt++;
			// cout << i + 'a' << "\n";
		}
		cout << ans + (cnt / 2) << "\n";
	}
	return 0;
}