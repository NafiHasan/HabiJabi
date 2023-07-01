#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc ;
	while (tc--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		int start = 0;
		bool ans = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				start = i;
				ans = true;
				break;
			}
		}
		int left = start - 1, right = start + 1;
		char c = 'a';
		while (ans) {
			c++;
			if (left >= 0 && s[left] == c) {
				left--;
				continue;
			} else if (right < n && s[right] == c) {
				right++;
				continue;
			} else if (left < 0 && right >= n)break;
			else {
				ans = false;
				break;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}