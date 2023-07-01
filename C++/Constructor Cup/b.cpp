#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int r = 0, c = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'D')r--;
			if (s[i] == 'R')c++;
			if (s[i] == 'L')c--;
			if (s[i] == 'U')r++;
		}
		int ans = abs(r) + abs(c);
		cout << ans << '\n';
	}
	return 0;
}