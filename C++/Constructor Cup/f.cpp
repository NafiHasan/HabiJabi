#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


bool check(string s) {
	int n = s.size();
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == 'O') {
			if (i >= 2 && s[i - 1] != s[i - 2]) {
				return 1;
			}
			if (i + 3 < n && s[i + 2] != s[i + 3]) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		bool alice = 0;
		int n = s.size();
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1] && s[i] == 'X') {
				if (i >= 2 && s[i - 1] != s[i - 2]) {
					alice = 1;
					break;
				}
				if (i + 3 < n && s[i + 2] != s[i + 3]) {
					alice = 1;
					break;
				}
			}
		}
		if (alice) {
			cout << "Alice\n";
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1] && s[i] == 'O') {
				if (i >= 2 && s[i - 1] != s[i - 2]) {
					cnt++;
				}
				if (i + 3 < n && s[i + 2] != s[i + 3]) {
					cnt++;
				}
			}
		}
		bool ans = 1;
		for (int i = 0; i < n - 1; i++) {
			swap(s[i], s[i + 1]);
			ans &= check(s);
			swap(s[i], s[i + 1]);
		}

		if (ans)cout << "Bob\n";
		else cout << "Tie\n";
	}
	return 0;
}