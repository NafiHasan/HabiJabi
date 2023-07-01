#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool pal = 1;
		string t = s;
		reverse(t.begin(), t.end());
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i])pal = 0;
		}
		if (pal || k < 1) {
			cout << "1\n";
		} else cout << "2\n";
	}
	return 0;
}