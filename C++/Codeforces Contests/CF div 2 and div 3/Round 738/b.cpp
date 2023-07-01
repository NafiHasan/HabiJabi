#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;
		bool yes = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R' || s[i] == 'B')yes = 1;
		}
		if (yes == 0) {
			for (int i = 0; i < n; i++) {
				if (i % 2)s[i] = 'R';
				else s[i] = 'B';
			}
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (s[j] == '?')continue;
					if (j == 0 && s[j + 1] == '?') {
						if (s[j] == 'B')s[j + 1] = 'R';
						else s[j + 1] = 'B';
					} else if (j == n - 1 && s[j - 1] == '?') {
						if (s[j] == 'B')s[j - 1] = 'R';
						else s[j - 1] = 'B';
					} else {
						if (s[j - 1] == '?') {
							if (s[j] == 'B')s[j - 1] = 'R';
							else s[j - 1] = 'B';
						}
						if (s[j + 1] == '?') {
							if (s[j] == 'B')s[j + 1] = 'R';
							else s[j + 1] = 'B';
						}
					}
				}
			}
		}
		cout << s << "\n";
	}
	return 0;
}