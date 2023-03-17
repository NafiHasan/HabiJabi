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
		vector<string> a(n - 2);
		for (int i = 0; i < n - 2; i++)cin >> a[i];
		string s = "";
		s += a[0][0];
		for (int i = 1; i < n - 2; i++) {
			if (a[i][0] != a[i - 1][1]) {
				s += a[i - 1][1];
				s += a[i][0];
			} else s += a[i][0];
		}
		s += a[n - 3][1];
		if (s.size() < n)s += 'a';
		cout << s << '\n';
	}
	return 0;
}