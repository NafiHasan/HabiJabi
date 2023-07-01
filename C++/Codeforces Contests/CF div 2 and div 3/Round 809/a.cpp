#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		string s(m, 'B');
		// cout << s << '\n';
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int mn = min(m - a[i], a[i] - 1);
			int mx = max(m - a[i], a[i] - 1);
			if (s[mn] == 'B') {
				s[mn] = 'A';
			} else {
				s[mx] = 'A';
			}
		}
		cout << s << '\n';
	}
	return 0;
}