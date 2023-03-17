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
		string s;
		cin >> s;
		int cnt1 = 0;
		for (int i = 0; i < n; i++)if (s[i] == '1')cnt1++;
		if (cnt1 > (n - cnt1)) {
			for (int i = 0; i < n; i++)if (s[i] == '1')cout << s[i];
			cout << '\n';
		} else {
			for (int i = 0; i < n; i++)if (s[i] == '0')cout << s[i];
			cout << '\n';
		}
	}
	return 0;
}