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
		string s, my;
		cin >> s >> my;
		int ans = 0;
		for (int i = 0; i < n ; i++) {
			if (my[i] == '0')continue;
			if (s[i] == '0')ans++;
			else if (i &&  s[i - 1] == '1') {
				ans++;
				s[i - 1] = '2';
			} else if (i < n - 1  && s[i + 1] == '1') {
				ans++;
				s[i + 1] = '2';
			}
		}
		cout << ans << "\n";
	}
	return 0;
}