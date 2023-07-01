#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc; cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int cnta = 0, cntb = 0;
		bool ans = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a') {
				cnta++;
				if (cntb > 0 && cntb == 1)ans = 0;
				cntb = 0;
			} else {
				cntb++;
				if (cnta == 1)ans = 0;
				cnta = 0;
			}
		}
		if (cnta == 1 || cntb == 1)ans = 0;
		if (ans)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}