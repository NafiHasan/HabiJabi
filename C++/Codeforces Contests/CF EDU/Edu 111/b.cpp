#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		if (b >= 0) {
			cout << n*a + n*b << "\n";
		} else {
			int ans = 1;
			char first = s[0];
			for (int i = 0; i < s.size(); i++) {
				if (i && s[i] != first && s[i - 1] == first)ans++;
				// else if (i == 0 && s[i] == '0')ans++;
			}
			cout << a*n + (ans * b) << "\n";
		}
	}
	return 0;
}